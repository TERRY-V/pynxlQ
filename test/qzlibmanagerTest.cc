#include <iostream>
#include "../core/qzlibmanager.h"

using namespace std;
using namespace niu;

int main(int argc, char** argv)
{
	QZlibManager qzm;
	int ret=qzm.init(1024);
	if(ret) {
		cout<<"init ret = "<<ret<<endl;
		return -1;
	}

	char src[]="我是中国人，我爱自己的祖国。I am a Chinese, I love my country!思考地看待似懂非懂的发顺丰顶顶顶顶顶顶顶顶顶顶顶顶顶顶顶顶顶顶顶顶事实上";
	int srclen=strlen(src);
	printf("srclen = %d\n", srclen);

	char dest[1024]={0};
	ret=qzm.gzip_compress((uint8_t*)src, srclen, (uint8_t*)dest, sizeof(dest));
	if(ret<0) {
		cout<<"compress ret = "<<ret<<endl;
		return -1;
	}

	printf("ret = (%d)\n", ret);
	printf("out = (%.*s)\n", ret, dest);

	char out[1024]={0};
	ret=qzm.gzip_uncompress((uint8_t*)dest, ret, (uint8_t*)out, sizeof(out));
	if(ret<0) {
		cout<<"compress ret = "<<ret<<endl;
		return -1;
	}

	printf("ret = (%d)\n", ret);
	printf("out = (%.*s)\n", ret, out);

	return 0;
}
