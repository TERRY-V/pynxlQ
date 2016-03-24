#include <iostream>
#include "mailer.h"

using namespace std;

int main(int argc, char** argv)
{
	jwsmtp::mailer m("suping@hither.com.cn", "niuxiaolin@hither.com.cn", \
			"ÓÊ¼ş²âÊÔ", "ÓÊ¼şÄÚÈİ", \
			"smtp.exmail.qq.com", jwsmtp::mailer::SMTP_PORT, \
			false);
	m.addrecipient("niuxiaolin@hither.com.cn");

	m.username("niuxiaolin@hither.com.cn");
	m.password("niu123");

	while(1) {
		m.send();
		cout<<m.response()<<endl;
	}

	return 0;
}
