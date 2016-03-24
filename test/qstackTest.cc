#include <iostream>
#include "../common/qstack.h"

using namespace std;
using namespace niu;

bool checkBracketMatching(const char* str)
{
	QStack<char> stk;
	const char* p=str;
	char ch=0;

	while(*p) {
		switch(*p) {
			case '(':
			case '[':
				stk.push(*p++);
				break;
			case ')':
			case ']':
				stk.pop(ch);
				if((*p==')'&&ch=='(') || (*p==']'&&ch=='[')) p++;
				else return false;
				break;
			default:
				p++;
				break;
		}
	}
	return stk.empty()?true:false;
}

int main()
{
	std::cout<<checkBracketMatching("[(())]")<<std::endl;
	return 0;
}
