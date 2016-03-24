#include <iostream>
#include <fstream>

#include "niuxl.helloworld.pb.h"

void ListMsg(const niuxl::helloworld& message)
{
	std::cout<<message.id()<<std::endl;
	std::cout<<message.str()<<std::endl;
}

int main(int argc, char** argv)
{
	niuxl::helloworld message;
	{
		std::fstream input("./log", std::ios::in|std::ios::binary);
		if(!message.ParseFromIstream(&input)) {
			std::cerr<<"Failed to parse message."<<std::endl;
			return -1;
		}
	}

	ListMsg(message);

	return 0;
}
