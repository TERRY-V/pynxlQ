#include "../core/qhttpserver.h"

using namespace niu;

int32_t main(int32_t argc, char** argv)
{
	QHttpServer qhs;

	int32_t ret=qhs.init("__webserver.cfg");
	if(ret<0) {
		Q_INFO("init error, ret = %d", ret);
		return -1;
	}

	qhs.start();

	return 0;
}
