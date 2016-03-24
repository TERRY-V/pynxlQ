#include "../common/qdiskcache.h"

Q_USING_NAMESPACE

int main(int argc, char** argv)
{
	QDiskCache<uint64_t> *qhs=new QDiskCache<uint64_t>();
	assert(qhs!=NULL);

	int32_t ret=0;

#if 1
	ret=qhs->init(1048576, 0, 10);
	assert(ret==0);

	/*
	for(int i=100000; i!=190000; ++i) {
		ret=qhs->addKey_FL(i);
		if(ret<0) {
			printf("ret = (%d), i = (%d)\n", ret, i);
			break;
		}
	}
	*/

	qhs->addKey_FL(88888);

	if(qhs->searchKey_FL(100001)==0) {
		printf("true\n");
	} else {
		printf("false\n");
	}

	q_serve_forever();
#else

	ret=qhs->init(1048576, -1);
	assert(ret>=0);

	char buf[100];
	for(int i=1000000; i!=1900000; ++i) {
		snprintf(buf, 100, "order<%d>", i);
		void* p=NULL;
		int len;
		ret=qhs->addKey_VL(i, (void*)buf, strlen(buf), &p, &len);
		if(ret<0) {
			printf("ret = (%d), i = (%d)\n", ret, i);
			break;
		} else {
			//printf("inserted: (%.*s)\n", len, p);
		}
	}

	void* p=NULL;
	int len;
	if(qhs->searchKey_VL(1300000, &p, &len)==0)
		printf("true: (%.*s)\n", len, p);
	else
		printf("false\n");
#endif

	return 0;
}
