#include "qserialization.h"

using namespace std;

int main()
{
	char buf[1024]={0};
	int64_t pos=0;
	int8_t value8=15;
	int16_t value16=16262;
	int32_t value32=677222222;
	int64_t value64=666666666666;
	int32_t iret=QSerialization::set_int32(buf, sizeof(buf), pos, value32);
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}

	iret=QSerialization::set_int8(buf, sizeof(buf), pos, value8);
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}

	iret=QSerialization::set_int16(buf, sizeof(buf), pos, value16);
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}

	iret=QSerialization::set_int64(buf, sizeof(buf), pos, value64);
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}

	iret=QSerialization::set_string(buf, sizeof(buf), pos, "你好啊");
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}

	int64_t pos2=0;
	int8_t val8;
	int16_t val16;
	int32_t val32;
	int64_t val64;
	char str[1024]={0};

	iret=QSerialization::get_int32(buf, sizeof(buf), pos2, &val32);
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}
	cout<<val32<<endl;

	iret=QSerialization::get_int8(buf, sizeof(buf), pos2, &val8);
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}
	cout<<(int32_t)val8<<endl;

	iret=QSerialization::get_int16(buf, sizeof(buf), pos2, &val16);
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}
	cout<<val16<<endl;

	iret=QSerialization::get_int64(buf, sizeof(buf), pos2, &val64);
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}
	cout<<val64<<endl;

	int64_t ret_len=0;
	iret=QSerialization::get_string(buf, sizeof(buf), pos2, sizeof(str), str, ret_len);
	if(iret<0) {
		Q_DEBUG("bad %d", iret);
		return -1;
	}
	cout<<str<<'\t'<<ret_len<<endl;

	return 0;
}
