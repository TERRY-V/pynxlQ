#include "../core/qhttpclient.h"

using namespace std;
using namespace niu;

int main()
{
	QHttpRequestHeader request_header;
	//request_header.setURL("http://blog.sina.com.cn/s/blog_74a7e56e0102v7zf.html");
	request_header.setURL("http://db.house.qq.com/bj_120919/");

	QHttpClient qhr;
	char buffer[1<<20]={0};
	int32_t ret=qhr.request(request_header, buffer, sizeof(buffer));
	if(ret<0) {
		Q_INFO("ret = %d", ret);
		return -2;
	}

	printf("ret = (%d)\n", ret);
	printf("out = (%.*s)\n", ret, buffer);

	return 0;
}
