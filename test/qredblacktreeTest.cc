#include <iostream>
#include "qredblacktree.h"

using namespace std;

int main()
{
	QRedBlackTree<int, string> qrbt;

	qrbt.insert(20044390, "niuxl");
	qrbt.insert(20024390, "11111");
	qrbt.insert(20234390, "33333");
	qrbt.insert(20344390, "fffff");
	qrbt.insert(20042390, "22222");
	qrbt.insert(20044392, "nssss");
	qrbt.insert(20044395, "nddds");
	qrbt.insert(20044391, "ns4xl");
	qrbt.insert(20044391, "ns4xl");
	qrbt.insert(20044398, "ns4xl");
	qrbt.insert(20044397, "ns4xl");

	cout<<qrbt.size()<<endl;
	qrbt.height();

	qrbt.remove(20044395);

	string buf;
	qrbt.search(20044391, buf);
	cout<<buf<<endl;

	return 0;
}
