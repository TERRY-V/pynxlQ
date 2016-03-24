#include "qvector.h"

using namespace std;

Q_USING_NAMESPACE

int main()
{
	QVector<string> vec;

	string a1="niuxl";
	string a2="xl";
	string a3="peiying";
	string a4="wze";
	string a5="sss";
	vec.push_back(a1);
	vec.push_back(a2);
	vec.push_back(a3);
	vec.push_back(a4);
	vec.push_back(a5);

	vec.sort();

	for(int i=0; i!=vec.size(); ++i) {
		cout<<vec[i]<<endl;
	}

	cout<<vec.size()<<endl;
	cout<<vec.max_size()<<endl;
	return 0;
}
