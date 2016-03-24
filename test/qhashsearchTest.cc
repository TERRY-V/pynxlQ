#include "../core/qhashsearch.h"

Q_USING_NAMESPACE

int main(int argc, char** argv)
{
	QHashSearch<uint64_t> *qhs=new QHashSearch<uint64_t>();
	assert(qhs!=NULL);

	int32_t ret=0;

#if 1
	ret=qhs->init(1048576, 5);
	assert(ret==0);

	for(int i=100000; i!=190000; ++i) {
		ret=qhs->addKey_FL(i, (void*)"ttttt");
		if(ret<0) {
			printf("ret = (%d), i = (%d)\n", ret, i);
			break;
		}
	}

	/*
	ret=qhs->save("a.txt");
	assert(ret>=0);
	//ret=qhs->load((char*)("a.txt"));
	//assert(ret>=0);

	ret=qhs->deleteKey_FL(20044392);
	assert(ret>=0);

	ret=qhs->prepareTraverseKey();
	assert(ret>=0);

	uint64_t key;
	char* retbuf=NULL;
	int datalen=0;

	while(qhs->traverse(key, (void*&)retbuf, datalen)!=-1)
		printf("%ld\t%s\n", key, retbuf);
		*/

	ret=qhs->updateKey_FL(130000, (void*)"sssss");
	printf("ret = %d\n", ret);

	void* res=NULL;
	if(qhs->searchKey_FL(130001, &res)==0) {
		printf("true\n");
		printf("%.*s\n", 5, (char*)res);
	} else {
		printf("false\n");
	}

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
