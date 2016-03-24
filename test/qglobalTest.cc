#include <iostream>
#include "../common/qglobal.h"

using namespace std;

Q_USING_NAMESPACE

void heart_beat(int signo)
{
	cout<<signo<<'\t'<<"I love you!"<<endl;
}

void testWatchdog()
{
	QWatchdog qts;
	qts.set_now(1000);
	qts.set_interval(3000);
	qts.start(heart_beat);

	q_sleep(10000);
}

void testByteSwap()
{
	char buf[32];

	sprintf(buf, "ciaoroma");
	q_byte_swap16(buf);
	printf("%s\n", buf);

	sprintf(buf, "ciaoroma");
	q_byte_swap32(buf);
	printf("%s\n", buf);

	sprintf(buf, "ciaoroma");
	q_byte_swap64(buf);
	printf("%s\n", buf);

	cout<<q_byte_swap(uint16_t(300))<<endl;
	cout<<q_byte_swap(uint32_t(120000))<<endl;
	cout<<q_byte_swap(uint64_t(1200000000))<<endl;
}

void testRandom()
{
	QRandom qrd;
	int aa[3]={0, 1, 2};
	while(1) {
		int tt=qrd.get_random_int32(0, 5);
		cout<<tt<<'\t'<<aa[tt]<<endl;
	}
	/*
	cout<<qrd.get_random_int32(10, 100)<<endl;
	cout<<qrd.get_random_int32(10, 100)<<endl;
	cout<<qrd.get_random_int32(10, 100)<<endl;
	cout<<qrd.get_random_int32(10, 100)<<endl;
	cout<<qrd.get_random_int32(10, 100)<<endl;
	cout<<qrd.get_random_int32(0, 1)<<endl;
	cout<<qrd.get_random_int32(0, 1)<<endl;
	cout<<qrd.get_random_int32(0, 1)<<endl;
	cout<<qrd.get_random_int32(0, 1)<<endl;
	cout<<qrd.get_random_int32(0, 1)<<endl;
	cout<<qrd.get_random_float01()<<endl;
	cout<<qrd.get_random_float01()<<endl;
	cout<<qrd.get_random_float01()<<endl;
	cout<<qrd.get_random_float01()<<endl;
	cout<<qrd.get_random_float01()<<endl;
	cout<<qrd.get_random_float01()<<endl;
	cout<<qrd.get_random_int64(10000000000000, 20000000000000)<<endl;
	cout<<qrd.get_random_int64(10000000000000, 20000000000000)<<endl;
	cout<<qrd.get_random_int64(10000000000000, 20000000000000)<<endl;
	cout<<qrd.get_random_int64(10000000000000, 20000000000000)<<endl;
	cout<<qrd.get_random_int64(10000000000000, 20000000000000)<<endl;
	cout<<qrd.get_random_int64(10000000000000, 20000000000000)<<endl;

	char buf[32]={0};
	qrd.get_random_buffer(buf, sizeof(buf)-1, "abcdefghijklmnopqrstuvwxyz ");
	cout<<buf<<endl;
	*/
}

void testVersion()
{
	if(Q_VERSION>=Q_VERSION_CHECK(2, 0, 0)) {
		cout<<"good"<<endl;
	} else {
		cout<<"bad"<<endl;
	}
}

void testStringBuffer()
{
	QStringBuffer stringBuffer;
	stringBuffer.append(23455);
	stringBuffer.append("Hello, world");
	stringBuffer.append('!');
	cout<<stringBuffer.length()<<endl;
	cout<<stringBuffer.max_size()<<endl;
	cout<<stringBuffer.getBuffer()<<endl;
}

void testAssert()
{
	Q_ASSERT(1==0, "ssssssssssssss%d", 122);
	Q_ASSERT_X(1==0, __FILE__, __LINE__, __FUNCTION__, "ssssssssssss%d", 444444444);
	Q_STATIC_ASSERT(1==1, must_be_true);
}

void testDebug()
{
	DEBUG_FUNC(
			printf("Hello world!\n");
		  );
}

void testHexDump()
{
	char str[]="我是中国人，我非常热爱我的祖国，难道这也有问题吗？";
	q_hex_dump("Hello", str, strlen(str)); 
}

void testLimit()
{
	int32_t ret=0;
	uint32_t rlimit_cur=0;
	uint32_t rlimit_max=0;
	ret=q_getrlimit(RLIMIT_NPROC, rlimit_cur, rlimit_max);
	if(ret<0) {
		Q_INFO("q_getrlimit ret = (%d)", ret);
		exit(0);
	} else {
		Q_INFO("rlimit_cur = (%d), rlimit_max = (%d)", rlimit_cur, rlimit_max);
	}

	ret=q_setrlimit(RLIMIT_NPROC, 4096);
	if(ret<0) {
		Q_INFO("q_setrlimit ret = (%d)", ret);
		exit(0);
	}

	ret=q_getrlimit(RLIMIT_NPROC, rlimit_cur, rlimit_max);
	if(ret<0) {
		Q_INFO("q_getrlimit ret = (%d)", ret);
		exit(0);
	} else {
		Q_INFO("rlimit_cur = (%d), rlimit_max = (%d)", rlimit_cur, rlimit_max);
	}
}

void testHex()
{
	uint64_t num=122222222222222222;
	printf("%0lx\n", num);
}

int main(int argc, char** argv)
{
	//testWatchdog();
	//testByteSwap();
	//testRandom();
	//testVersion();
	//testStringBuffer();
	//testAssert();
	//testDebug();
	//testHexDump();
	//testLimit();
	//testHex();
	return 0;
}
