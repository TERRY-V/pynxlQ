/********************************************************************************************
**
** Copyright (C) 2010-2015 Terry Niu (Beijing, China)
** Filename:	qaeepoll.h
** Author:	TERRY-V
** Email:	cnbj8607@163.com
** Support:	http://blog.sina.com.cn/terrynotes
** Date:	2015/04/12
**
*********************************************************************************************/

#ifndef __QAEEPOLL_H_
#define __QAEEPOLL_H_

#include "qglobal.h"

Q_BEGIN_NAMESPACE

typedef struct aeApiState {
	int32_t epfd;
	struct epoll_event* events;
};

static int32_t aeApiCreate(aeEventLoop* eventLoop)
{
	aeApiState* state=q_malloc(sizeof(aeApiState));
	if(!state) return -1;

	state->events=q_malloc(sizeof(struct epoll_event)*eventLoop->setSize);
	if(!state->events) {
		q_free(state);
		return -2;
	}

	state->epfd=epoll_create(1024);	// 1024 is just a hint for the kernel
	if(state->epfd==-1) {
		q_free(state->events);
		q_free(state);
		return -3;
	}

	eventLoop->apidata=state;
	return 0;
}

static int32_t aeApiResize(aeEventLoop* eventLoop, int32_t setSize)
{
	aeApiState* state=eventLoop->apidata;
	state->events=q_realloc(state->events, sizeof(struct epoll_event)*setSize);
	return 0;
}

static void aeApiFree(aeEventLoop* eventLoop)
{
	aeApiState* state=eventLoop->apidata;
	close(state->epfd);
	q_free(state->events);
	q_free(state);
}

static int32_t aeApiAddEvent(aeEventLoop* eventLoop, int32_t fd, int32_t mask)
{
	aeApiState* state=eventLoop->apidata;
	struct epoll_event ee;

	// If the fd was already monitored for some event, we need a MOD operation.
	// Otherwise we need an ADD operation.
	int32_t op=eventLoop->events[fd].mask==AE_NONE?EPOLL_CTL_ADD:EPOLL_CTL_MOD;

	ee.events=0;
	mask|=eventLoop->events[fd].mask;	// Merge old events
	if(mask&AE_READABLE) ee.events|=EPOLLIN;
	if(mask&AE_WRITABLE) ee.events|=EPOLLOUT;
	ee.data.u64=0;	// avoid valgrind warning
	ee.data.fd=fd;
	if(epoll_ctl(state->epfd, op, fd, &ee)==-1) return -1;
	return 0;
}

static void aeApiDelEvent(aeEventLoop* eventLoop, int32_t fd, int32_t delmask)
{
	aeApiState* state=eventLoop->apidata;
	struct epoll_event ee;
	int32_t mask=eventLoop->events[fd].mask&(~delmask);

	ee.events=0;
	if(mask&AE_READABLE) ee.events|=EPOLLIN;
	if(mask&AE_WRITABLE) ee.events|=EPOLLOUT;
	ee.data.u64=0;	// avoid valgrind warning
	ee.data.fd=fd;
	if(mask!=AE_NONE) {
		epoll_ctl(state->epfd, EPOLL_CTL_MOD, fd, &ee);
	} else {
		epoll_ctl(state->epfd, EPOLL_CTL_DEL, fd, &ee);
	}
}

static int32_t aeApiPoll(aeEventLoop* eventLoop, struct timeval* tvp)
{
	aeApiState* state=eventLoop->apidata;
	int32_t retval, numevents=0;

	retval=epoll_wait(state->epfd, state->events, eventLoop->setsize, tvp?(tvp->tv_sec*1000+tvp->tv_usec/1000):-1);
	if(retval>0) {
		numevents=retval;
		for(int32_t j=0; j<numevents; ++j) {
			int32_t mask=0;
			struct epoll_event* e=state->events+j;

			if(e->events&EPOLLIN) mask|=AE_READABLE;
			if(e->events&EPOLLOUT) mask|=AE_WRITABLE;
			if(e->events&EPOLLERR) mask|=AE_WRITABLE;
			if(e->events&EPOLLHUP) mask|=AE_WRITABLE;
			eventLoop->fired[j].fd=e->data.fd;
			eventLoop->fired[j].mask=mask;
		}
	}
	return numevents;
}

static char* aeApiName(void)
{
	return "epoll";
}

Q_END_NAMESPACE

#endif // __QAEEPOLL_H_
