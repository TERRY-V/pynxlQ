#include <iostream>
#include "qstring.h"

using namespace std;
using namespace nxl;

int main(int argc, char** argv)
{
	QString ss("你好an是");
	QString str=ss.right(2);
	cout<<str<<endl;
	cout<<str.length()<<endl;
	cout<<str.max_size()<<endl;
	
	/*
	for(int i=0; i!=ss.size(); ++i)
		cout<<ss[i].toLatin1()<<endl;
	*/

	/*
	QString s1="中国人";
	QString s2(1024);
	s2=s1.append("好棒!");
	cout<<s1<<endl;
	cout<<s1.length()<<endl;
	cout<<s1.max_size()<<endl;
	cout<<s2<<endl;
	cout<<s2.length()<<endl;
	cout<<s2.max_size()<<endl;
	*/

	//QString s3=" 你 好 \r 周 \n 杰伦 ";
	//QString s4="你好a";
	/*
	cout<<(s3==s4)<<endl;
	cout<<(s3=="你好a")<<endl;
	cout<<(s3!=s4)<<endl;
	cout<<(s3!="你好a")<<endl;
	*/

	/*
	list<QString> qlist=s3.line_tokenize();
	cout<<qlist.size()<<endl;
	for(list<QString>::iterator it=qlist.begin(); it!=qlist.end(); ++it)
		cout<<it->length()<<'\t'<<*it<<endl;
		*/

	return 0;
}
