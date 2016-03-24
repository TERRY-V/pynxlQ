#include "../core/qsocketpool.h"

using namespace niu;

int main(int argc, char** argv)
{
	QSocketPool qsp("192.168.118.128", 8088, 3000);

	int32_t ret=qsp.init();
	if(ret<0) {
		Q_DEBUG("init error, ret = (%d)", ret);
		return -1;
	}

	q_serve_forever();

	return 0;
}
