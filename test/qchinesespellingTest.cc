#include "../nlp/qchinesespelling.h"

using namespace niu;

int main()
{
	QChineseSpelling qcs;

	int32_t ret=qcs.init((char*)"../nlp/__spelling.dat");
	if(ret<0) {
		Q_INFO("int error, ret = %d", ret);
		return -1;
	}

	char buf[1024]={0};
	ret=qcs.to_spelling((char*)"ÄãºÃ°¡", 6, buf, sizeof(buf));
	if(ret<0) {
		Q_INFO("to_spelling error, ret = %d", ret);
		return -2;
	}

	Q_INFO("ret = %d", ret);
	Q_INFO("buf = %s", buf);

	return 0;
}
