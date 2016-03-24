#include "qdatastream.h"

using namespace std;
using namespace niu;

int main()
{
	QDataStream qds(1024);

	int32_t iret=qds.set_int32(100);
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}

	iret=qds.set_int8(10);
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}

	iret=qds.set_int16(1030);
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}

	iret=qds.set_int64(17665550230);
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}

	iret=qds.set_string("sssss");
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}

	cout<<qds.get_data_length()<<endl;
	cout<<qds.get_free_length()<<endl;

	int8_t val8;
	int16_t val16;
	int32_t val32;
	int64_t val64;
	char str[1024]={0};

	iret=qds.get_int32(&val32);
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}
	cout<<val32<<endl;

	iret=qds.get_int8(&val8);
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}
	cout<<(int32_t)val8<<endl;

	iret=qds.get_int16(&val16);
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}
	cout<<val16<<endl;

	iret=qds.get_int64(&val64);
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}
	cout<<val64<<endl;

	int64_t real_length=0;
	iret=qds.get_string(sizeof(str), str, real_length);
	if(iret<0) {
		cout<<iret<<endl;
		return -1;
	}
	cout<<str<<'\t'<<real_length<<endl;

	return 0;
}
