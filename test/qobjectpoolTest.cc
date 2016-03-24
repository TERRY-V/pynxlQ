#include <iostream>
#include "qobjectpool.h"

using namespace std;

Q_USING_NAMESPACE

class UserRequest {
	public:
		UserRequest() {cout<<"construct......"<<endl;}
		virtual ~UserRequest() {cout<<"destruct......"<<endl;}

		void print() {cout<<"I am an object......"<<endl;}
};

int main()
{
	QObjectPool<UserRequest> pool(20);
	cout<<"Loop starting......"<<endl;
	for(size_t i=0; i<50; ++i) {
		UserRequest* request=pool.acquireObject();
		request->print();
		pool.releaseObject(request);
	}
	return 0;
}
