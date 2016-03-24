#include <iostream>
#include <fstream>

#include "niuxl.helloworld.pb.h"

int main(int argc, char** argv)
{
	niuxl::helloworld message;
	message.set_id(1001);
	message.set_str("Hello, world!");

	std::fstream output("./log", std::ios::out|std::ios::trunc|std::ios::binary);

	if(!message.SerializeToOstream(&output)) {
		std::cerr<<"Failed to write message."<<std::endl;
		return -1;
	}

	return 0;
}
