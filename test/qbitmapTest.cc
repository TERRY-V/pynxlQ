#include "../core/qbitmap.h"

using namespace std;
using namespace niu;

int main(int argc, char** argv)
{
	QBITS16 val;
	val.turn_on_bit(4);
	cout<<val.bit(4)<<endl;
	val.turn_off_bit(4);
	cout<<val.bit(4)<<endl;
	val.set_bit(12, 1);
	cout<<val.bit(12)<<endl;

	QBitMap qbm(10000000, 0);
	qbm.turn_on_bit(999);
	cout<<qbm.bit(999)<<endl;
	qbm.turn_off_bit(999);
	cout<<qbm.bit(999)<<endl;

	QBitMap2 bs(1000000);
	if(bs.turn_on_bit(100000)) {
		cout<<"good......"<<endl;
	} else {
		cout<<"false......"<<endl;
	}
	std::cout<<bs.bit(100000)<<std::endl;

	return 0;
}
