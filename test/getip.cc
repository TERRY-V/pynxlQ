#include <iostream>
#include "../common/qfunc.h"
#include "../common/qnetworkaccessmanager.h"
#include "../common/qmailsender.h"
#include "../common/qtextcodec.h"

using namespace std;
using namespace niu;

void getip()
{
	// 创建邮件发送类对象
	QMailSender *qms=new QMailSender();
	assert(qms!=NULL);

	// 设置登陆用户名
	qms->setUser("cnbj8607@126.com");
	// 设置密码
	qms->setPasswd("sssss");
	// 设置smtp服务器
	qms->setSmtpServer("smtp://smtp.126.com");
	// 设置发信人
	qms->setMailFrom("cnbj8607@126.com");
	// 设置收件人
	qms->addRecipient("80720365@qq.com");

	// 获取本机的IP地址
	QNetworkAccessManager *networkManager=new QNetworkAccessManager();
	if(networkManager->init()==-1) {
		cout<<"QNetworkAccessManager::init failed......"<<endl;
		return;
	}

	networkManager->setUserAgent();
	networkManager->setCookieEnabled();

	std::string ip_last("");
	while(1)
	{
		char html[1<<20]={0};
		int32_t ret=networkManager->doHttpGet("http://1212.ip138.com/ic.asp", 10000, html, sizeof(html));
		if(ret<0) {
			cout<<"GET ip failed..."<<endl;
			q_sleep(1000);
			continue;
		}

		std::string content(html, ret);
		std::string ip_str=q_substr(content, "<center>", "</center>");
		std::string ip_now=QTextCodec::gbk2utf8(ip_str);

		// 发送邮件
		if(ip_last!=ip_now) {
			ip_last=ip_now;
			cout<<"IP = "<<ip_now<<endl;
			qms->sendMail("亲, 格林格林的IP地址已发生了变化...", ip_now.c_str());
		}

		q_sleep(10000);
	}

	delete networkManager;
	networkManager=NULL;

	delete qms;
	qms=NULL;
}

int main(int argc, char** argv)
{
	getip();
	return 0;
}
