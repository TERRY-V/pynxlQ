#include "../common/qgramtree.h"

Q_USING_NAMESPACE
using namespace std;

int main()
{
	QGramTree gramTree;

	int32_t ret=gramTree.init();
	Q_ASSERT(ret==0, "init error!");

	string groupName("ROLE");
	string meaning("DATE");
	vector<string> grams;

	ret=gramTree.query(groupName, meaning, grams);
	if(ret<0) {
		cout<<"query_error"<<endl;
		return -1;
	}

	cout<<"--------------------------------------------"<<endl;
	cout<<"Group Name: "<<groupName<<endl;
	cout<<"Meaning: "<<meaning<<endl;
	for(int i=0; i<grams.size(); ++i)
		printf("(%02d) %s\n", i, grams[i].c_str());
	cout<<"--------------------------------------------"<<endl;

	return 0;
}
