#include "../common/qdistance.h"

using namespace std;
using namespace niu;

int main(int argc, char** argv)
{
	unordered_map<string, double> c1, c2;

	c1.insert(std::make_pair("hello", 0.02));
	c1.insert(std::make_pair("world", 0.02));
	c1.insert(std::make_pair("good", 0.02));
	c1.insert(std::make_pair("bad", 0.02));

	c2.insert(std::make_pair("hello", 0.02));
	c2.insert(std::make_pair("world", 0.02));
	c2.insert(std::make_pair("good", 0.02));
	c2.insert(std::make_pair("bad", 0.02));

	cout<<QDistance::calL1Norm(c1, c2)<<endl;
	cout<<QDistance::calL2Norm(c1, c2)<<endl;
	cout<<QDistance::calLInfiniteNorm(c1, c2)<<endl;
	cout<<QDistance::calCosineDistance(c1, c2)<<endl;

	cout<<QDistance::calMinEditDistance("1111", 4, "1122", 4)<<endl;

	return 0;
}
