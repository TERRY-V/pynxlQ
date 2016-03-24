#include <iostream>
#include "../core/qqueue.h"

using namespace std;
using namespace niu;

int main()
{
#if 1
	QQueue<int32_t> que;
	que.init(100);
	cout<<que.max_size()<<endl;
	for(int32_t i=0; i<100; ++i) {
		que.push(i);
		cout<<i<<endl;
	}
	cout<<que.size()<<endl;

	while(1) {
		int32_t t=que.pop();
		cout<<t<<endl;
	}

#else

	QListQueue<int32_t> que(150);
	cout<<que.max_size()<<endl;
	que.push(3);
	que.push(5);
	que.push(6);
	que.push(8);
	que.push_urgent(10);
	que.push(4);
	cout<<que.size()<<endl;

	while(1) {
		int32_t t=que.pop();
		cout<<t<<endl;
	}
#endif

#if 0
	QPriorityQueue<string> que;
	que.init(1000);
	cout<<que.max_size()<<endl;
	//while(!que.full()) {
		que.push("niuxl");
		que.push("suping");
		que.push("peiying");
		que.push("peiying");
	//}
	cout<<que.size()<<endl;

	//while(!que.empty()) {
	while(1) {
		string t=que.pop();
		cout<<t<<endl;
	}
#endif

	return 0;
}
