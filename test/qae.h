/********************************************************************************************
**
** Copyright (C) 2010-2015 Terry Niu (Beijing, China)
** Filename:	qae.h
** Author:	TERRY-V
** Email:	cnbj8607@163.com
** Support:	http://blog.sina.com.cn/terrynotes
** Date:	2015/04/12
**
*********************************************************************************************/

#ifndef __QAE_H_
#define __QAE_H_

#include "qglobal.h"

#define AE_OK		(0)
#define AE_ERR		(-1)

#define AE_NONE		(0)
#define AE_READABLE	(1)
#define AE_WRITABLE	(2)

#define AE_FILE_EVENTS	(1)
#define AE_TIME_EVENTS	(2)
#define AE_ALL_EVENTS	(AE_FILE_EVENTS|AE_TIME_EVENTS)
#define AE_DONT_WAIT	(4)

#define AE_NOMORE	(-1)

#define AE_NOTUSED(V)	((void)V)

Q_BEGIN_NAMESPACE

struct aeEventLoop;

typedef void aeFileProc(struct aeEventLoop* eventLoop, int32_t fd, void* clientData, int32_t mask);
typedef int32_t aeTimeProc(struct aeEventLoop* eventLoop, int64_t id, void* clientData);
typedef void aeEventFinalizerProc(struct aeEventLoop* eventLoop, void* clientData);
typedef void aeBeforeSleepProc(struct aeEventLoop* eventLoop);

typedef struct aeFileEvent {
	int32_t mask;
	aeFileProc* rfileProc;
	aeFileProc* wfileProc;
	void* clientData;
} aeFileEvent;

typedef struct aeTimeEvent {
	int64_t id;
	int64_t when_sec;
	int64_t when_ms;
	aeTimeProc* timeProc;
	aeEventFinalizerProc* finalizerProc;
	void* clientData;
	struct aeTimeEvent* next;
} aeTimeEvent;

typedef struct aeFiredEvent {
	int32_t fd;
	int32_t mask;
} aeFiredEvent;

typedef struct aeEventLoop {
	int32_t maxfd;
	int32_t setsize;
	int64_t timeEventNextId;
	time_t	lastTime;
	aeFileEvent* events;
	aeFiredEvent* fired;
	aeTimeEvent* timeEventHead;
	int32_t stop;
	void* apidata;
	aeBeforeSleepProc* beforesleep;
} aeEventLoop;

static aeEventLoop* aeCreateEventLoop(int32_t setsize)
{
	aeEventLoop* eventLoop;

	if((eventLoop=q_malloc(sizeof(*eventLoop)))==NULL) goto err;
	eventLoop->events=q_malloc(sizeof(aeFileEvent)*setsize);
	eventLoop->fired=q_malloc(sizeof(aeFiredEvent)*setsize);
	if(eventLoop->events==NULL||eventLoop->fired==NULL) goto err;
	eventLoop->setsize=setsize;
	eventLoop->lastTime=time(NULL);
	eventLoop->timeEventHead=NULL;
	eventLoop->timeEventNextId=0;
	eventLoop->stop=0;
	eventLoop->maxfd=-1;
	eventLoop->beforesleep=NULL;
	if(aeApiCreate(eventLoop)==-1) goto err;
	for(int32_t i=0; i<setsize; ++i)
		eventLoop->events[i].mask=AE_NONE;
	return eventLoop;

err:
	if(eventLoop) {
		q_free(eventLoop->events);
		q_free(eventLoop->fired);
		q_free(eventLoop);
	}
	return NULL;
}

static int32_t aeGetSetSize(aeEventLoop* eventLoop)
{
	return eventLoop->setsize;
}

static int32_t aeResizeSetSize(aeEventLoop* eventLoop, int32_t setsize)
{
	if(setsize==eventLoop->setsize) return AE_OK;
	if(eventLoop->maxfd>=setsize) return AE_ERR;
	if(aeApiResize(eventLoop, setsize)==-1) return AE_ERR;

	eventLoop->events=q_realloc(eventLoop->events, sizeof(aeFileEvent)*setsize);
	eventLoop->fired=q_realloc(eventLoop->fired, sizeof(aeFiredEvent)*setsize);
	eventLoop->setsize=setsize;

	for(int32_t i=eventLoop->maxfd+1; i<setSize; ++i)
		eventLoop->events[i].mask=AE_NONE;
	return AE_NONE;
}

static void aeStop(aeEventStop* eventLoop)
{
	eventLoop->stop=1;
}

static int32_t aeCreateFileEvent(aeEventLoop* eventLoop, int32_t fd, int32_t mask, aeFileProc* proc, void* clientData)
{
	if(fd>=eventLoop->setsize) {
		errno=ERANGE;
		return AE_ERR;
	}

	aeFileEvent* fe=&eventLoop->events[fd];

	if(aeApiAddEvent(eventLoop, fd, mask)==-1)
		return AE_ERR;
	fe->mask|=mask;
	if(mask&AE_READABLE) fe->rfileProc=proc;
	if(mask&AE_WRITABLE) fe->wfileProc=proc;
	fe->clientData=clientData;
	if(fd>eventLoop->maxfd)
		eventLoop->maxfd=fd;
	return AE_OK;
}

static int32_t aeDeleteFileEvent(aeEventLoop* eventLoop, int32_t fd, int32_t mask)
{
	if(fd>=eventLoop->setsize) return;
	aeFileEvent* fe=&eventLoop->events[fd];
	if(fe->mask==AE_NONE) return;

	aeApiDelEvent(eventLoop, fd, mask);
	fe->mask=fe->mask&(~mask);
	if(fd==eventLoop->maxfd&&fe->mask==AE_NONE) {
		for(int32_t j=eventLoop->maxfd-1; j>=0; j--)
			if(eventLoop->events[j].mask!=AE_NONE) break;
		eventLoop->maxfd=j;
	}
}

static int32_t aeGetFileEvents(aeEventLoop* eventLoop, int32_t fd)
{
	if(fd>=eventLoop->setSize) return 0;
	aeFileEvents* fe=&eventLoop->events[fd];
	return fe->mask;
}

static void aeGetTime(int64_t* seconds, int64_t* milliseconds)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	*seconds=tv.tv_sec;
	*milliseconds=tv.tv_usec/1000;
}

static void aeAddMillisecondsToNow(int64_t milliseconds, int64_t* sec, int64_t* ms)
{
	int64_t cur_sec, cur_ms, when_sec, when_ms;

	aeGetTime(&cur_sec, &cur_ms);
	when_sec=cur_sec+milliseconds/1000;
	when_ms=cur_ms+milliseconds%1000;
	if(when_ms>=1000) {
		when_sec++;
		when_ms-=1000;
	}
	*sec=when_sec;
	*ms=when_ms;
}

static int64_t aeCreateTimeEvent(aeEventLoop* eventLoop, int64_t milliseconds, aeTimeProc* proc, void* clientData, aeEventFinalizerProc* finalizerProc)
{
	int64_t id=eventLoop->timeEventNextId++;
	aeTimeEvent* te;

	te=q_malloc(sizeof(*te));
	if(te==NULL) return AE_ERR;
	te->id=id;
	aeAddMillisecondsToNow(milliseconds, &te->when_sec, &te->when_ms);
	te->timeProc=proc;
	te->finalizerProc=finalizerProc;
	te->clientData=clientData;
	te->next=eventLoop->timeEventHead;
	eventLoop->timeEventHead=te;
	return id;
}

static int32_t addDeleteTimeEvent(aeEventLoop* eventLoop, int64_t id)
{
	aeTimeEvent *te, *prev=NULL;

	te=eventLoop->timeEventHead;
	while(te) {
		if(te->id==id) {
			if(prev==NULL)
				eventLoop->timeEventHead=te->next;
			else
				prev->next=te->next;
			if(te->finalizerProc)
				te->finalizerProc(eventLoop, te->clientData);
			q_free(te);
			return AE_OK;
		}
		prev=te;
		te=te->next;
	}
	return AE_ERR;
}

static aeTimeEvent *aeSearchNearestTimer(aeEventLoop *eventLoop)
{
	aeTimeEvent *te=eventLoop->timeEventHead;
	aeTimeEvent *nearest=NULL;

	while(te) {
		if(!nearest||te->when_sec<nearest->when_sec|| \
				(te->when_sec==nearest->when_sec&&te->when_ms<nearest->when_ms))
			nearest=te;
		te=te->next;
	}
	return nearest;
}

static int32_t processTimeEvent(aeEventLoop* eventLoop)
{
	int32_t processed=0;
	aeTimeEvent* te;
	int64_t maxId;
	time_t now=time(NULL);

	if(now<eventLoop->lastTime) {
		te=eventLoop->timeEventHead;
		while(te) {
			te->when_sec=0;
			te=te->next;
		}
	}
	eventLoop->lastTime=now;

	te=eventLoop->timeEventHead;
	maxId=eventLoop->timeEventNextId-1;
	while(te) {
		int64_t now_sec, now_ms;
		int64_t id;

		if(te->id>maxId) {
			te=te->next;
			continue;
		}

		aeGetTime(&now_sec, &now_ms);
		if(now_sec>te->when_sec||(now_sec==te->when_sec&&now_ms>=te->when_ms)) {
			int32_t retval;

			id=te->id;
			retval=te->timeProc(eventLoop, id, te->clientData);
			processed++;

			if(retval!=AE_NOMORE) {
				aeAddMillisecondsToNow(retval, &te->when_sec, &te->when_ms);
			} else {
				aeDeleteTimeEvent(eventLoop, id);
			}
			te=eventLoop->timeEventHead;
		} else {
			te=te->next;
		}
	}
	return processed;
}

int32_t aeProcessEvents(aeEventLoop* eventLoop, int32_t flags)
{
	int32_t processed=0, numevents;

	if(!(flags&AE_TIME_EVENTS)&&(!flags&AE_FILE_EVENTS))
		return 0;

	if(eventLoop->maxfd!=-1||((flags&AE_TIME_EVENTS)&&!(flags&AE_DONT_WAIT))) {
		int32_t j;
		aeTimeEvent *shortest=NULL;
		struct timeval tv, *tvp;

		if(flags&AE_TIME_EVENTS&&!(flags&AE_DONT_WAIT))
			shortest=aeSearchNearestTimer(eventLoop);

		if(shortest) {
			long now_sec, now_ms;

			aeGetTime(&now_sec, &now_ms);
			tvp=&tv;
			tvp->tv_sec=shortest->when_sec-now_sec;
			if(shortest->when_ms<now_ms) {
				tvp->tv_usec=((shortest->when_ms+1000)-now_ms)*1000;
				tvp->tv_sec--;
			} else {
				tvp->tv_usec=(shortest->when_ms-now_ms)*1000;
			}
			if(tvp->tv_sec<0) tvp->tv_sec=0;
			if(tvp->tv_usec<0) tvp->tv_usec=0;
		} else {
			if(flags&AE_DONT_WAIT) {
				tv.tv_sec=tv.tv_usec=0;
				tvp=&tv;
			} else {
				tvp=NULL;
			}
		}

		numevents=aeApiPoll(eventLoop, tvp);
		for(j=0; j<numevents; j++) {
			aeFileEvent *fe=&eventLoop->events[eventLoop->fired[j].fd];
			int32_t mask=eventLoop->fired[j].mask;
			int32_t fd=eventLoop->fired[j].fd;
			int32_t rfired = 0;

			if(fe->mask&mask&AE_READABLE) {
				rfired=1;
				fe->rfileProc(eventLoop, fd, fe->clientData, mask);
			}
			if(fe->mask&mask&AE_WRITABLE) {
				if(!rfired||fe->wfileProc!=fe->rfileProc)
					fe->wfileProc(eventLoop, fd, fe->clientData, mask);
			}
			processed++;
		}
	}

	if(flags&AE_TIME_EVENTS)
		processed+=processTimeEvents(eventLoop);

	return processed;
}

static int32_t aeWait(int32_t fd, int32_t mask, int64_t milliseconds)
{
	struct pollfd pfd;
	int32_t retmask=0, retval;

	memset(&pfd, 0, sizeof(pfd));
	pfd.fd=fd;
	if(mask&AE_READABLE) pfd.events|=POLLIN;
	if(mask&AE_WRITABLE) pfd.events|=POLLOUT;

	if((retval=poll(&pfd, 1, milliseconds))==1) {
		if(pfd.revents&POLLIN) retmask|=AE_READABLE;
		if(pfd.revents&POLLOUT) retmask|=AE_WRITABLE;
		if(pfd.revents&POLLERR) retmask|=AE_WRITABLE;
		if(pfd.revents&POLLHUP) retmask|=AE_WRITABLE;
		return retmask;
	} else {
		return retval;
	}
}

static void aeMain(aeEventLoop* eventLoop)
{
	eventLoop->stop=0;
	while(!eventLoop->stop) {
		if(eventLoop->beforesleep!=NULL)
			eventLoop->beforesleep(eventLoop);
		aeProcessEvents(eventLoop, AE_ALL_EVENTS);
	}
}

static char* aeGetApiName(void)
{
	return aeApiName();
}

static void aeSetBeforeSleepProc(aeEventLoop *eventLoop, aeBeforeSleepProc *beforesleep)
{
	eventLoop->beforesleep=beforesleep;
}

Q_END_NAMESPACE

#endif // __QAE_H_
