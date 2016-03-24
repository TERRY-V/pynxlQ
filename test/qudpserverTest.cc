#include "../core/qudpsocket.h"

using namespace niu;

int main(int argc, char** argv)
{
	QUdpServer quc;
	void* sock=NULL;

	int32_t ret=quc.init(6543, 10);
	if(ret<0) {
		Q_DEBUG("ret = %d", ret);
		return -1;
	}

	quc.start();

	q_serve_forever();

	return 0;
}
