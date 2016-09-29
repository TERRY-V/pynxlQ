#include <iostream>
#include <cstdio>
#include "../common/qglobal.h"
#include "../common/qmd5.h"

using namespace std;
using namespace niu;

int main()
{
	QMD5 qmd5;
	char str[1<<20]="Hello, world!";

	//FILE* fp=fopen("a.jpg", "rb");
	//int32_t file_size=q_get_file_size("a.jpg");
	//fread(str, file_size, 1, fp);

	//uint32_t val1=qmd5.MD5Bits32((unsigned char*)str, strlen(str));
	//cout<<val1<<endl;

#if 1
	//uint64_t val2=qmd5.MD5Bits64((unsigned char*)"Hello world!", 12);
	uint64_t val2=2655436793;
	printf("%lu\n", val2);
	printf("%llx\n", val2);
#endif

	/*
	FILE *FP1=fopen("b.txt", "wb");
	fwrite(&val2, 8, 1, FP1);

	printf("%lx\n", val2);
	*/

	/*
	unsigned char output[256]={0};
	qmd5.MD5Bits128(output, (unsigned char*)str, strlen(str));
	cout<<output<<endl;
	*/

	return 0;
}
