#include <iostream>
#include "../common/MD5.h"

int main(int argc, char** argv)
{
	std::cout<<md5("Hello world!")<<std::endl;
	std::cout<<md5("Hello world!", 12)<<std::endl;
	return 0;
}
