#include "../common/qjaccardsimilarity.h"

using namespace niu;

void testJaccardSimilarity()
{
	std::list<uint64_t> list1=QJaccardSimilarity::kHashShingle("瞻东A风电榆团结", 1);
	std::list<uint64_t> list2=QJaccardSimilarity::kHashShingle("瞻榆团结东B风电", 1);
	double sim=QJaccardSimilarity::calc(list1, list2);
	std::cout<<sim<<std::endl;
}

int main()
{
	testJaccardSimilarity();
	return 0;
}
