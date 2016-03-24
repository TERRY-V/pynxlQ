#include <iostream>
#include "../common/qconfigreader.h"

using namespace std;
using namespace niu;

int main()
{
	QConfigReader conf;
	if(conf.init("__config.conf")==0) {
		cout<<"init ok"<<endl;
	} else {
		cout<<"bad...."<<endl;
		exit(0);
	}
	
	int alarminterval;
	int ret=conf.getFieldInt32("alarminterval", alarminterval);
	if(ret>=0) {
		cout<<alarminterval<<endl;
	} else {
		cout<<ret<<endl;
	}

	double criticalrate;
	ret=conf.getFieldDouble("criticalrate", criticalrate);
	if(ret>=0) {
		cout<<criticalrate<<endl;
	} else {
		cout<<ret<<endl;
	}

	char fileName[1024]={0};
	ret=conf.getFieldString("filepath", fileName, 1024);
	if(ret>=0) {
		cout<<fileName<<'\t'<<strlen(fileName)<<endl;
	} else {
		cout<<ret<<endl;
	}

	int hour, minute, second;
	ret=conf.getFieldTime("time", hour, minute, second);
	if(ret>=0) {
		cout<<hour<<'\t'<<minute<<'\t'<<second<<'\t'<<ret<<endl;
	} else {
		cout<<ret<<endl;
	}

	char* pFile=NULL;
	ret=conf.getFieldString("test-alloc", pFile);
	if(ret>=0) {
		cout<<pFile<<'\t'<<strlen(pFile)<<endl;
	} else {
		cout<<ret<<endl;
	}

	q_free(pFile);

	int yesno;
	ret=conf.getFieldYesNo("yesorno", yesno);
	if(ret>=0) {
		cout<<yesno<<endl;
	} else {
		cout<<ret<<endl;
	}

	return 0;
}
