#include "../common/qremotemonitor.h"

using namespace niu;

int32_t call_back(void* ptr_info)
{
	return 0;
}

int main(int argc, char** argv)
{
	QRemoteMonitor qrm;

	if(qrm.init(7655, 10000, call_back, NULL, 1)) {
		Q_INFO("QRemoteMonitor: init error!");
		return -1;
	}

	q_serve_forever();

	return 0;
}
