#include <iostream>
#include "../leveldb/leveldb-master/include/leveldb/db.h"

// g++ -o leveldbTest leveldbTest.cc -I../leveldb/leveldb-master/ ../leveldb/leveldb-master/libleveldb.a -lpthread

int main(int argc, char** argv)
{
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, "__data.ldb", &db);
	assert(status.ok());

	std::string key = "key";
	std::string value = "value";

	status = db->Put(leveldb::WriteOptions(), key, value);
	assert(status.ok());
	status = db->Get(leveldb::ReadOptions(), key, &value);
	assert(status.ok());

	std::cout<<key<<"==>"<<value<<std::endl;

	std::string key2 = "key2";
	status = db->Put(leveldb::WriteOptions(), key2, value);
	assert(status.ok());

	status = db->Delete(leveldb::WriteOptions(), key);
	assert(status.ok());

	status = db->Get(leveldb::ReadOptions(), key2, &value);
	assert(status.ok());

	std::cout<<key2<<"==>"<<value<<std::endl;

	status = db->Get(leveldb::ReadOptions(), key, &value);
	if(!status.ok())
		std::cerr<<status.ToString()<<std::endl;
	else
		std::cout<<key<<"==>"<<value<<std::endl;

	delete db;
	return 0;
}
