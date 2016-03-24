#include "../common/qredisclient.h"

using namespace niu;

int main(int argc, char** argv)
{
	QRedisClient qrc;
	if(qrc.connect("127.0.0.1", 6379)) {
		printf("connect error...\n");
		return -1;
	}

	qrc.ping();

	qrc.set("str1", "qqqqqqqqq");
	qrc.set("str2", "sssssssss");
	qrc.set("str3", "333333333");
	qrc.set("str4", "444444444");
	qrc.set("str5", "555555555");

	qrc.exists("str4");

	Q_INFO("%s", qrc.get("str3").c_str());

	return 0;
}
