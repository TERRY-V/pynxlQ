#include <iostream>
#include "../common/qlogicalparser.h"

using namespace niu;
using namespace std;

int main()
{
	vector<string> meaningList;
	meaningList.push_back("UK");
	meaningList.push_back("PM");
	meaningList.push_back("N");

	QLogicalParser lp;
	std::cout<<lp.parse("UK&PM|P|N&!PM", "是的", meaningList)<<std::endl;

	return 0;
}
