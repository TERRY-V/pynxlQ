#include <iostream>
#include "../common/MD5.h"

int main(int argc, char** argv)
{
	std::cout<<md5("23a596c8fb8efe48d522dd5a173830b06490190114606204416732764")<<std::endl;
	std::cout<<md5("Hello world!", 12)<<std::endl;
	return 0;
}
