#include "../common/qmongoclient.h"

Q_USING_NAMESPACE

// g++ -o qmongoclientTest qmongoclientTest.cc ../common/qmongoclient.cc -lpthread -I /usr/include/mongo-client-install/include/ /usr/include/mongo-client-install/lib/libmongoclient.a -lboost_system -lboost_thread -lboost_regex -lboost_date_time

int main(int argc, char** argv)
{
	QMongoClient client("mongodb://192.168.1.122:27017");
	int32_t ret = MONGO_OK;

	client.setCollection("yunshitu.adk_log");
	client.selectAll();

	return 0;
}
