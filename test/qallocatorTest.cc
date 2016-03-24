#include <iostream>
#include "../common/qallocator.h"

using namespace std;
using namespace niu;

int main()
{
	// 总计能分配1M的内存
	QAllocator* allocator=new QAllocator(1000, 1024);
	char* p1=allocator->alloc(1024);
	Q_ASSERT(p1!=NULL, "p1==null");
	strcpy(p1, "niuxl");

	char* p2=allocator->alloc(800);
	Q_ASSERT(p2!=NULL, "p2==null");
	strcpy(p2, "peiying");

	char* p3=allocator->alloc(200);
	strcpy(p3, "hello");

	cout<<p1<<endl;
	cout<<p2<<endl;

	cout<<allocator->getAllocLength()<<endl;
	cout<<allocator->getBufferLength()<<endl;

	//////////////////////////////////////////////////////////////////
	
	QPoolAllocator poolAllocator;

	int32_t ret=poolAllocator.init(10, 1000, 10);
	Q_ASSERT(ret==0, "ret = %d", ret);

	char* p=NULL;
	p=poolAllocator.alloc();
	poolAllocator.trace("poolAllocator");
	p=poolAllocator.alloc();
	poolAllocator.trace("poolAllocator");
	p=poolAllocator.alloc();
	poolAllocator.trace("poolAllocator");
	poolAllocator.free(p);
	poolAllocator.trace("poolAllocator");
	poolAllocator.free(p);
	poolAllocator.trace("poolAllocator");
	poolAllocator.free(p);
	poolAllocator.trace("poolAllocator");
	p=poolAllocator.alloc();
	poolAllocator.trace("poolAllocator");
	p=poolAllocator.alloc();
	poolAllocator.trace("poolAllocator");
	p=poolAllocator.alloc();
	poolAllocator.trace("poolAllocator");

	cout<<poolAllocator.getChunkSize()<<endl;

	return 0;
}
