#include "../common/qlbscheduler.h"

using namespace niu;

int main(int argc, char** argv)
{
	QLBScheduler lbs;

	int ret=lbs.init("__sched.conf");
	if(ret<0) {
		Q_INFO("ret = %d", ret);
		return -1;
	}

	lbs.trace();

	for(int i=0; i<100; ++i) {
		struct serverInfo server;
		int server_index=lbs.get_server(&server);
		printf("server index = (%d), address = (%s)\n", server_index, server.addr.c_str());
	}

	q_serve_forever();

	return 0;
}
