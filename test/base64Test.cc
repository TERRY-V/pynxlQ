#include "../common/base64.h"

int main(int argc, char** argv)
{
#if 1
	const char input[] = "hello world";
	char output[1024] = {0};

	int len = base64_encode(input, 11, output);
	assert(len>0);

	printf("encode = [%d] (%s)\n", len, output);
#else
	const char input[] = "aGVsbG8gd29ybGQ=";
	char output[1024] = {0};

	int len = base64_decode(input, 16, output);
	assert(len>0);

	printf("decode = [%d] (%s)\n", len, output);
#endif

	return 0;
}
