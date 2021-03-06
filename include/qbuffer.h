/********************************************************************************************
**
** Copyright (C) 2010-2014 Terry Niu (Beijing, China)
** Filename:	qbuffer.h
** Author:	TERRY-V
** Email:	cnbj8607@163.com
** Support:	http://blog.sina.com.cn/terrynotes
** Date:	2014/03/28
**
*********************************************************************************************/

#ifndef __QBUFFER_H_
#define __QBUFFER_H_

#include "qglobal.h"

Q_BEGIN_NAMESPACE

class QBuffer {
	public:
		inline QBuffer() :
			pstart_(NULL),
			pend_(NULL),
			pfree_(NULL),
			pdata_(NULL)
		{}

		virtual ~QBuffer()
		{destroy();}

		inline void destroy()
		{
			if(NULL!=pstart_) {
				free(pstart_);
				pend_=pfree_=pdata_=pstart_=NULL;
			}
		}

		inline char* get_data() const
		{return reinterpret_cast<char*>(pdata_);}

		inline int64_t get_data_length() const
		{return (pfree_-pdata_);}

		inline char* get_free() const
		{return reinterpret_cast<char*>(pfree_);}

		inline int64_t get_free_length() const
		{return (pend_-pfree_);}

		inline int64_t get_buf_length() const
		{return (pend_-pstart_);}

		inline int32_t drain(const uint64_t length)
		{
			int32_t iret=(NULL!=pdata_)?0:-1;
			if(iret==0) {
				pdata_+=length;
				if(pdata_>=pfree_)
					clear();
			}
			return iret;
		}

		inline int32_t pour(const uint64_t length)
		{
			Q_ASSERT((uint64_t)(pend_-pfree_)>=length, "QBuffer: length is larger than left buffer size.");
			int32_t iret=(NULL!=pfree_)?0:-1;
			if(iret==0)
				pfree_+=length;
			return iret;
		}

		inline int32_t strip(const uint64_t length)
		{
			Q_ASSERT((uint64_t)(pend_-pdata_)>=length, "QBuffer: length is larger than the buffer size.");
			int32_t iret=(NULL!=pfree_)?0:-1;
			if(iret==0)
				pfree_-=length;
			return iret;
		}

		inline void clear()
		{pdata_=pfree_=pstart_;}

		inline void expand(const int64_t need)
		{
			if(NULL==pstart_) {
				int64_t length=DEFAULT_MALLOC_SIZE;
				while(length<need)
					length<<=EXPAND_MULTIPLE;
				pfree_=pdata_=pstart_=(unsigned char*)malloc(length);
				pend_=pstart_+length;
			} else if(get_free_length()<need) {
				int64_t free_length=get_free_length()+(pdata_-pstart_);
				int64_t data_length=get_data_length();
				if(free_length<need||free_length*4<data_length) {
					int64_t buf_size=get_buf_length();
					buf_size<<=EXPAND_MULTIPLE;
					while((buf_size-data_length)<need)
						buf_size<<=EXPAND_MULTIPLE;
					unsigned char* newbuf=(unsigned char*)malloc(buf_size);
					Q_ASSERT(newbuf!=NULL, "QBuffer::expand, newbuf is null!");
					if(data_length>0)
						memcpy(newbuf, pdata_, data_length);
					free(pstart_);
					pdata_=pstart_=newbuf;
					pfree_=pstart_+data_length;
					pend_=pstart_+buf_size;
				} else {
					memmove(pstart_, pdata_, data_length);
					pfree_=pstart_+data_length;
					pdata_=pstart_;
				}
			}
		}

		inline bool shrink()
		{
			bool bret=(NULL!=pstart_);
			if(bret) {
				if((pend_-pstart_)<=SHRINK_BUFFER_SIZE||(pfree_-pdata_)<=SHRINK_BUFFER_SIZE)
					bret=false;
				if(bret) {
					int64_t old_length=pfree_-pdata_;
					if(old_length<0)
						old_length=0;
					unsigned char* newbuf=(unsigned char*)malloc(SHRINK_BUFFER_SIZE);
					Q_ASSERT(newbuf!=NULL, "QBuffer::shrink, newbuf is null!");
					if(old_length>0)
						memcpy(newbuf, pdata_, old_length);
					free(pstart_);
					pdata_=pstart_=newbuf;
					pfree_=pstart_+old_length;
					pend_=pstart_+SHRINK_BUFFER_SIZE;
				}
			}
			return bret;
		}

	private:
		Q_DISABLE_COPY(QBuffer);
		static const int16_t DEFAULT_MALLOC_SIZE=1<<8;
		static const int16_t SHRINK_BUFFER_SIZE=2<<10;
		static const int8_t EXPAND_MULTIPLE=1;
		unsigned char* pstart_;
		unsigned char* pend_;
		unsigned char* pfree_;
		unsigned char* pdata_;
};

Q_END_NAMESPACE

#endif // __QBUFFER_H_
