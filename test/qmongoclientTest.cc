#include "../common/qmongoclient.h"

Q_USING_NAMESPACE

// g++ -o qmongoclientTest qmongoclientTest.cc ../common/qmongoclient.cc -lpthread -I /usr/include/mongo-client-install/include/ /usr/include/mongo-client-install/lib/libmongoclient.a -lboost_system -lboost_thread -lboost_regex -lboost_date_time

int main(int argc, char** argv)
{
	QMongoClient client("mongodb://localhost:27017");
	int32_t ret = MONGO_OK;

	client.setCollection("niuxl.recginfo");
	client.dropCollection();

	char buf[1024]={0};
	for(uint64_t i = 100000; i < 100010; ++i)
	{
		sprintf(buf, "%lu", i);

		ret = client.insert(buf,  "Hello, world!");
		if(ret == MONGO_ERR) {
			Q_INFO("insert error");
			continue;
		}
	}

	
	ret = client.remove("100006");
	if(ret == MONGO_ERR) {
		Q_INFO("remove error!");
		return -2;
	}

	std::cout<<client.exists("10003")<<std::endl;
	std::cout<<client.exists("100003")<<std::endl;

	ret = client.update("100003", "ssssssssssssni hao!");
	if (ret == MONGO_ERR) {
		Q_INFO("update error");
		return -3;
	}

	return 0;
}
