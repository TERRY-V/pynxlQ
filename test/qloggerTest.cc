#include "../common/qlogger.h"

using namespace niu;

int32_t main(int32_t argc, char** argv)
{
	int32_t count=0;
	while(count++<=10) {
		Q_LOG_INFO("logging %d sss\n33333333......", count);
		Q_LOG_ERROR("logging %d ......", count);
		Q_LOG_ALERT("logging %d ......", count);
		Q_LOG(DEBUG, "logging %d ......", count);
		Q_LOG_WARNING("logging %d ......", count);
	}

	return 0;
}
