#include "../common/qcrc.h"

using namespace niu;

int main(int argc, char** argv)
{
	Q_INFO("%d", crc16("Hello, world", 12));
	Q_INFO("%u", crc32(0, (char*)"123456789", 9));
	Q_INFO("%llu", crc64(0, (uint8_t*)"123456789", 9));
	return 0;
}
