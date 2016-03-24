#include <iostream>
#include "qocrmanager.h"

using namespace std;

int main()
{
	char str_text[BUFSIZ_1K]={0};

	QOcrManager ocr;
	int32_t ret=ocr.init();
	if(ret) {
		cout<<"Init: ret = "<<ret<<endl;
		return -1;
	}

	ocr.setWhiteList();

	ret=ocr.process_image("CheckCode0566.jpg", str_text, sizeof(str_text));
	if(ret<0) {
		cout<<"ret = "<<ret<<endl;
		return -1;
	} else {
		cout<<"ret = "<<ret<<endl;
		cout<<"Text: "<<str_text<<endl;
	}

	cout<<ocr.getVersion()<<endl;

	return 0;
}
