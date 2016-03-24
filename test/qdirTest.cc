#include "../common/qdir.h"

using namespace niu;
using namespace std;

void testTraverseDir()
{
	QDir qd;

	char buf[1024];
	cout<<qd.getcwd(buf, sizeof(buf))<<endl;

	if(!qd.opendir()) {
		Q_INFO("baddddddddddddddddddddddddddd");
		abort();
	}

	char fileName[128]={0};
	while(qd.readdir(fileName))
		std::cout<<fileName<<std::endl;

	qd.closedir();
}

int main(int argc, char** argv)
{
	//QDir qd("./");
	//Q_INFO("%d", qd.exists("__file.txt"));
	//Q_INFO("%s", qd.path().c_str());
	//std::cout<<qd.remove("__file.txt")<<std::endl;
	//std::cout<<qd.rename("__file.txt", "file.txt")<<std::endl;
	//std::cout<<qd.exists("file.txt")<<std::endl;
	//std::cout<<qd.getcwd()<<std::endl;
	//
	QDir::mkdir("hello");
	QDir::chmod777("hello");

	return 0;
}
