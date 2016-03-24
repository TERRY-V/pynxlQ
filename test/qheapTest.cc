#include <iostream>
#include "qheap.h"

using namespace std;
using namespace nxl;

int main()
{
	QMaxHeap<string> heap(1000);
	cout<<heap.max_size()<<endl;
	//while(!heap.full()) {
		heap.push("suping");
		heap.push("niuxl");
		heap.push("aoyou");
		heap.push("zoyou");
		heap.push("peiying");
	//}
	cout<<heap.size()<<endl;

	//while(!heap.empty()) {
	while(1) {
		string t=heap.pop();
		cout<<t<<endl;
	}
	return 0;
}
