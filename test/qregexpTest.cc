#include <iostream>
#include "../common/qregexp.h"

using namespace std;
using namespace niu;

int main(int argc, char** argv)
{
#if 0
	QRegExp reg;
	reg.setPattern("([a-zA-Z]+) [0-9]+");
	//cout<<reg.pattern()<<endl;

	string ss="Hallo 11 robert";

	// 测试regex_match
	cout<<reg.regex_match(ss)<<endl;

	// 测试regex_sub
	vector<string> subs=reg.regex_sub(ss);
	for(vector<string>::iterator it=subs.begin(); it!=subs.end(); ++it)
		cout<<"substring: "<<*it<<endl;
#endif

	char src[]="111<title>Hello World</title><content>世界,你好</content>222<title>Good morning</title><content>早上好</content>niy";
	QRegExp reg("<title>([^<]*)</title><content>([^<]*)</content>");

	int unit_size=0;

	int pos[30];
	int ret=reg.regex_sub_all(src, strlen(src), unit_size, pos, 30);
	if(ret<=0) {
		printf("ret=%d\n", ret);
		return -3;
	}
	printf("unit_size = (%d)\n", unit_size);

	for(int i=0; i<ret; ++i) {
		char* str_start=src+pos[2*i];
		int str_len=pos[2*i+1]-pos[2*i];
		printf("%02d: %.*s\n", i, str_len, str_start);
	}

	char buf[1024]={0};
	char* pTemp=buf;
	char* pEnd=pTemp+sizeof(buf);
	for(int i=0; i!=ret/unit_size; ++i) {
		int32_t rc=snprintf(pTemp, pEnd-pTemp, "<record>\n");
		pTemp+=rc;
		for(int j=1; j!=unit_size; ++j) {
			rc=snprintf(pTemp, pEnd-pTemp, "<param>%.*s</param>\n", pos[unit_size*i*2+2*j+1]-pos[unit_size*i*2+2*j], src+pos[unit_size*2*i+2*j]);
			pTemp+=rc;
		}
		rc=snprintf(pTemp, pEnd-pTemp, "</record>\n");
		pTemp+=rc;
	}
	printf("%.*s\n", (int)(pTemp-buf), buf);

	vector<string> subs=reg.regex_sub_all(src, unit_size);
	cout<<"unit_size = "<<unit_size<<endl;
	for(vector<string>::iterator it=subs.begin(); it!=subs.end(); ++it)
		cout<<"substring: "<<*it<<endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*
	char src[]="111<title>Hello World</title><content>世界,你好</content>222<title>Good morning</title><content>早上好</content>niy";
	//char pattern[]="<title>.*</title>";

	QRegExp2 regexp;
	int32_t ret=regexp.init(100);
	if(ret<0) {
		printf("ret=%d\n", ret);
		return -1;
	}

	ret=regexp.compile_from_file("__regex.conf");
	//ret=regexp.compile(pattern, strlen(pattern));
	if(ret<0) {
		printf("ret=%d\n", ret);
		return -2;
	}

	int pos[30];
	int uSize=0;
	ret=regexp.exec_looping(src, strlen(src), uSize, pos, 30);
	if(ret<=0) {
		printf("ret=%d\n", ret);
		return -3;
	}

	printf("uSize = (%d)\n", uSize);

	for(int i=0; i<ret; ++i) {
		char* str_start=src+pos[2*i];
		int str_len=pos[2*i+1]-pos[2*i];
		printf("%02d: %.*s\n", i, str_len, str_start);
	}

	char buf[1024]={0};
	char* pTemp=buf;
	char* pEnd=pTemp+sizeof(buf);
	for(int i=0; i!=ret/uSize; ++i) {
		int32_t rc=snprintf(pTemp, pEnd-pTemp, "<record>\n");
		pTemp+=rc;
		for(int j=1; j!=uSize; ++j) {
			rc=snprintf(pTemp, pEnd-pTemp, "<param>%.*s</param>\n", pos[uSize*i*2+2*j+1]-pos[uSize*i*2+2*j], src+pos[uSize*2*i+2*j]);
			pTemp+=rc;
		}
		rc=snprintf(pTemp, pEnd-pTemp, "</record>\n");
		pTemp+=rc;
	}
	printf("%.*s\n", pTemp-buf, buf);
	*/

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*
	QRegExp3 test;
	test.compile("title", "<title>([^<]*)</title>");
	test.compile("content", "<content>([^<]*)</content><content>([^<]*)</content>");

	char str[]="<title>1111</title>sdd<title>2222</title><content>3333333</content><content>4444444</content>ssss";
	Q_INFO("str = (%s)", str);

	vector<REGEXP_INFO> regInfoVec;
	int ret=test.exec(str, strlen(str), regInfoVec);
	if(ret) {
		Q_INFO("ret = (%d)", ret);
		return -1;
	}

	for(int i=0; i<regInfoVec.size(); i++) {
		Q_INFO("%s", regInfoVec[i].name.c_str());
		for(int j=0; j<regInfoVec[i].value.size(); j++)
			Q_INFO("%s", regInfoVec[i].value[j].c_str());
	}
	*/

	return 0;
}
