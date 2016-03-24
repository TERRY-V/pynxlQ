#include <iostream>
#include "qtextcodec.h"

using namespace std;
using namespace nxl;

int main(int argc, char** argv)
{
	char src[1024]={0};
	strcpy(src, "你好啊");
	char dest[1024]={0};

	int ret=0;

	std::string ss=QTextCodec::utf82gbk(src);
	cout<<ss.length()<<'\t'<<ss<<endl;

	ss=QTextCodec::gbk2utf8(QTextCodec::utf82gbk(src));
	cout<<ss.length()<<'\t'<<ss<<endl;

	std::wstring wss=QTextCodec::utf82wstring("你们都好吗?");
	cout<<wss.length()<<endl;

	ss=QTextCodec::wstring2utf8(wss);
	cout<<ss.length()<<'\t'<<ss<<endl;

	ss=QTextCodec::wstring2gbk(L"你好啊");
	cout<<ss.length()<<'\t'<<ss<<endl;

	wss=QTextCodec::gbk2wstring(ss);
	cout<<wss.length()<<endl;

	/*
	ret=QTextCodec::utf82gbk(src, strlen(src), dest, sizeof(dest));
	if(ret<0) {
		cout<<"ret = "<<ret<<endl;
		return -1;
	} else {
		cout<<"ret = "<<ret<<endl;
		cout<<dest<<endl;
	}

	ret=QTextCodec::gbk2utf8(dest, ret, src, sizeof(src));
	if(ret<0) {
		cout<<"ret = "<<ret<<endl;
		return -1;
	} else {
		cout<<"ret = "<<ret<<endl;
		cout<<src<<endl;
	}

	ret=QTextCodec::gbk2unicode(dest, 6, src, sizeof(src));
	if(ret<0) {
		cout<<"ret = "<<ret<<endl;
		return -1;
	} else {
		cout<<"ret = "<<ret<<endl;
		cout<<src<<endl;
	}
	*/

	ret=QTextCodec::utf82unicode(src, 9, dest, sizeof(dest));
	if(ret<0) {
		cout<<"ret = "<<ret<<endl;
		return -1;
	} else {
		cout<<"ret = "<<ret<<endl;
		cout<<dest<<endl;
	}

	ret=QTextCodec::unicode2utf8(dest+2, ret-2, src, sizeof(src));
	if(ret<0) {
		cout<<"ret = "<<ret<<endl;
		return -1;
	} else {
		cout<<"ret = "<<ret<<endl;
		cout<<src<<endl;
	}

	return 0;
}
