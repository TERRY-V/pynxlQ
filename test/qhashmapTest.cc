#include "qhashmap.h"
#include "qmd5.h"

using namespace std;
using namespace nxl;

int main(int argc, char** argv)
{
	QHashMap2<string, int32_t> qhh(DefaultHash<string>(100000));
	qhh.insert(make_pair("niuxl", 26));
	qhh.insert(make_pair("supingssssssssssssssssssssssssssssss", 28));
	qhh.insert(make_pair("你好", 27));
	qhh.insert(make_pair("中国人", 32));

	cout<<"size: "<<qhh.size()<<endl;
	
	cout<<"bucket_size: "<<qhh.bucket_size()<<endl;

	cout<<"bucket: suping "<<qhh.bucket("suping")<<endl;
	cout<<"bucket: niuxl "<<qhh.bucket("niuxl")<<endl;
	cout<<"bucket: smile "<<qhh.bucket("smile")<<endl;
	cout<<"bucket: peiying "<<qhh.bucket("peiying")<<endl;

	int32_t val;
	if(qhh.find("你好", val)) {
		cout<<val<<endl;
	} else {
		cout<<"unknown..."<<endl;
	}

	/////////////////////////////////////////////////////////////////////////////////
	
	QHashMap<uint64_t, int32_t> qhh2(100000);
	qhh2.insert(make_pair(__uint64_t(873738383473343), 26));
	qhh2.insert(make_pair(__uint64_t(873738322223343), 27));
	qhh2.insert(make_pair(__uint64_t(873738333322343), 28));
	qhh2.insert(make_pair(__uint64_t(873738384333343), 29));
	qhh2.insert(make_pair(__uint64_t(873738382338343), 30));

	cout<<"size: "<<qhh2.size()<<endl;
	
	cout<<"bucket_size: "<<qhh2.bucket_size()<<endl;

	cout<<"bucket: __uint64_t(873738383473343)"<<qhh2.bucket(__uint64_t(873738383473343))<<endl;
	cout<<"bucket: __uint64_t(873738322223343)"<<qhh2.bucket(__uint64_t(873738322223343))<<endl;
	cout<<"bucket: __uint64_t(873738333322343)"<<qhh2.bucket(__uint64_t(873738333322343))<<endl;

	int32_t val2;
	if(qhh2.find(__uint64_t(873738333322343), val2)) {
		cout<<val2<<endl;
	} else {
		cout<<"unknown..."<<endl;
	}

	/////////////////////////////////////////////////////////////////////////////////
	
	/*
	QLinearHash<string, string> qht(1001);
	QMD5 qmd5;

	qht.push(qmd5.MD5Bits64((uint8_t*)"sp", 2), "sp", "suping");
	qht.push(qmd5.MD5Bits64((uint8_t*)"nxl", 3), "nxl", "niuxl");
	qht.push(qmd5.MD5Bits64((uint8_t*)"whc", 3), "whc", "wanghc");
	qht.push(qmd5.MD5Bits64((uint8_t*)"sjh", 3), "sjh", "shenjh");
	qht.push(qmd5.MD5Bits64((uint8_t*)"wzp", 3), "wzp", "wangzp");
	qht.push(qmd5.MD5Bits64((uint8_t*)"rxj", 3), "rxj", "rongxj");

	cout<<"buckets: "<<qht.bucket_size()<<endl;
	cout<<"size: "<<qht.size()<<endl;

	qht.prepareTraversal();
	string key, value;
	while(qht.traverse(key, value)==0)
		cout<<key<<'\t'<<value<<endl;

	string foundString;
	if(qht.search(qmd5.MD5Bits64((uint8_t*)"sjh", 3), "sjh", foundString)) {
		cout<<foundString<<endl;
	} else {
		cout<<"Not found..."<<endl;
	}
	*/

	return 0;
}
