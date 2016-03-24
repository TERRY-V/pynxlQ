#include "../common/qtcpsocket.h"

Q_USING_NAMESPACE

int main()
{
	niu::HelloWorldServer server;

	int ret=server.init();
	if(ret<0) {
		printf("error!\n");
		return -1;
	}

	server.start();

	return 0;
}
