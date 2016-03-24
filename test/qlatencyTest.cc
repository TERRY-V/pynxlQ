#include "../common/qlatency.h"

using namespace niu;

int main()
{
	QLatency latency;

	int32_t ret=latency.init();
	assert(ret==0);

	int32_t count=0;
	while(++count<100)
	{
		ret=latency.addLatencySample(count, rand()%15000);
		assert(ret==0);
	}

	ret=latency.createLatencyReport();
	assert(ret==0);
	return 0;
}
