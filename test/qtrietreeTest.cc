#include "../common/qtrietree.h"

using namespace std;
using namespace niu;

int main(int argc, char** argv)
{
	QTrieTree *qtt=new QTrieTree();
	Q_CHECK_PTR(qtt);

	int32_t ret=qtt->init();
	if(ret) {
		Q_DEBUG("ret = (%d)", ret);
		return -1;
	}

	qtt->insert((char*)"sp", 2);
	qtt->insert((char*)"xl", 2);
	qtt->insert((char*)"spla", 4);

	qtt->setupTrieIndex();

	ret=qtt->findByHash((char*)"xla1", 4);
	if(ret) {
		cout<<"query no data......"<<endl;
	} else {
		cout<<"query data ok......"<<endl;
	}

	std::vector<int32_t> posVec=qtt->getPossibleLength("xssplab", 7, 2);
	for(std::vector<int32_t>::iterator it=posVec.begin(); it!=posVec.end(); ++it)
		cout<<*it<<endl;

	delete qtt;

	return 0;
}
