#include "qlist.h"

using namespace std;
using namespace nxl;

struct Student {
	char name[30];
	int32_t age;

	Student() {}
	Student(char* pName, int32_t iAge) {strcpy(name, pName); age=iAge;}
};

int main(int argc, char** argv)
{
	QList<string> list;
	int count=0;
	//while(++count<10) {
		list.push_back("niuxl");
		list.push_back("peiying");
		list.push_front("suping");
	//}
	cout<<list.size()<<endl;

	list.prepareTraversal();
	while(list.hasPrev())
		cout<<list.prev()<<endl;

	QVector<string> vec=list.to_vector();
	for(int i=0; i!=vec.size(); ++i)
		cout<<vec.at(i)<<endl;

	///////////////////////////////////////////////////////////////////

	QForwardList<Student> qlm;
	int32_t ret=qlm.init(1000);
	if(ret<0) {
		cout<<"bad"<<endl;
		return -1;
	}

	qlm.add(Student("123456", 15));
	qlm.add(Student("sssss", 10));
	qlm.add(Student("ccccc", 20));
	qlm.add(Student("ffffff", 22));
	qlm.add(Student("ddddd", 18));

	cout<<qlm.size()<<endl;

	Student value;
	while(qlm.get(value)==0)
		cout<<value.name<<'\t'<<value.age<<endl;
	return 0;
}
