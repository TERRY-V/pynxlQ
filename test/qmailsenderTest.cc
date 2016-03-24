#include <iostream>
#include "cassert"
#include "qmailsender.h"

Q_USING_NAMESPACE

int main()
{
	// 创建邮件发送类对象
	QMailSender *qms=new QMailSender();
	assert(qms!=NULL);

	// 设置登陆用户名
	qms->setUser("cnbj8607@126.com");
	// 设置密码
	qms->setPasswd("ssss");
	// 设置smtp服务器
	qms->setSmtpServer("smtp.126.com");
	// 设置smtp服务器端口号
	qms->setPort(25);
	// 设置发信人
	qms->setMailFrom("cnbj8607@126.com");

	// 设置收件人
	qms->addRecipient("80720365@qq.com");

	// 发送邮件
	qms->sendMail("niuhao", "您好sss");

	return 0;
}
