#include "../core/qdenseindexmanager.h"

Q_USING_NAMESPACE

int main(int argc, char** argv)
{
	QDenseIndexManager *dim=new QDenseIndexManager();
	assert(dim!=NULL);

	int32_t ret=0;

	ret=dim->init("__dim");
	assert(ret>=0);

	dim->addKey(285, (void*)"11111", 5);
	dim->addKey(116, (void*)"2222222", 7);
	dim->addKey(70, (void*)"33333", 5);
	dim->addKey(923, (void*)"444444", 6);

	dim->rearrangeIndex();

	dim->deleteKey(70);

	char buf[100]={0};
	ret=dim->searchKey(70, buf, 100);
	if(ret>=0) {
		printf("true\n");
		Q_INFO("%.*s", ret, buf);
	} else {
		printf("false\n");
	}

	return 0;
}
