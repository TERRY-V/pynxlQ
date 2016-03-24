#include "../common/qmd5file.h"

using namespace niu;

int main()
{
	QMD5File qmf;

	char output[128]={0};
	int val=qmf.get_md5_string((char*)"84a933bc1232b9d4.jpg", output);
	std::cout<<output<<std::endl;
	std::cout<<val<<std::endl;

	return 0;
}
