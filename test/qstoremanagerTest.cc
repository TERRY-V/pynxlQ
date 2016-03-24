#include "../core/qstoremanager.h"

Q_USING_NAMESPACE

int main(int argc, char** argv)
{
	QStoreManager *qhs=new QStoreManager();
	assert(qhs!=NULL);

	int32_t ret=0;

#if 1
	ret=qhs->init("qsm", 7, 3, 5);
	assert(ret>=0);

#if 0
	qhs->addKey_FL(285, (void*)"11111");
	qhs->addKey_FL(116, (void*)"11111");
	qhs->addKey_FL(70, (void*)"11111");
	qhs->addKey_FL(923, (void*)"11111");
	qhs->addKey_FL(597, (void*)"11111");
	qhs->addKey_FL(204, (void*)"11111");
	qhs->addKey_FL(177, (void*)"11111");
	qhs->addKey_FL(512, (void*)"11111");
	qhs->addKey_FL(262, (void*)"11111");
	qhs->addKey_FL(246, (void*)"11111");
	qhs->addKey_FL(15, (void*)"11111");
	qhs->addKey_FL(76, (void*)"11111");
	qhs->addKey_FL(157, (void*)"11111");
	qhs->addKey_FL(635, (void*)"11111");
	qhs->addKey_FL(208, (void*)"11111");
	qhs->addKey_FL(337, (void*)"11111");
	qhs->addKey_FL(988, (void*)"11111");
	qhs->addKey_FL(817, (void*)"11111");
	qhs->addKey_FL(613, (void*)"11111");
	qhs->addKey_FL(575, (void*)"11111");
	qhs->addKey_FL(117, (void*)"76555");
	qhs->addKey_FL(540, (void*)"11111");
	qhs->addKey_FL(390, (void*)"11111");
	qhs->addKey_FL(362, (void*)"36522");
	qhs->addKey_FL(435, (void*)"11111");
#endif

	//qhs->deleteKey_FL(362);

	char buf[100]={0};
	if(qhs->searchKey_FL(362, buf, 100)==0) {
		printf("true\n");
		Q_INFO("%s", buf);
	} else {
		printf("false\n");
	}
#endif

#if 0
	ret=qhs->init("__hsm", 7, 3, -1);
	assert(ret>=0);

	qhs->addKey_VL(285, (void*)"11111", 5);
	qhs->addKey_VL(116, (void*)"2222222", 7);
	qhs->addKey_VL(70, (void*)"33333", 5);
	qhs->addKey_VL(923, (void*)"444444", 6);

	char buf[100]={0};
	if(qhs->searchKey_VL(923, buf, 100)>=0) {
		printf("true\n");
		Q_INFO("%s", buf);
	} else {
		printf("false\n");
	}
#endif

	return 0;
}
