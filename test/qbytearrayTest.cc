#include "../core/qbytearray.h"

using namespace std;
using namespace niu;

int main()
{
	QByteArray qba(1024);

	cout<<qba.size()<<endl;
	cout<<qba.remaining()<<endl;

	cout<<"position: "<<qba.position()<<endl;
	qba<<(int32_t)25;
	cout<<"position: "<<qba.position()<<endl;
	qba<<2393333333L;
	cout<<"position: "<<qba.position()<<endl;
	qba.put(string("您好!"));
	cout<<"position: "<<qba.position()<<endl;

	cout<<qba.remaining()<<endl;

	qba.position(0);
	
	int32_t val32;
	int64_t val64;
	string str;

	qba>>val32;
	qba>>val64;
	qba.get(str);

	cout<<val32<<endl;
	cout<<val64<<endl;
	cout<<str<<endl;

	return 0;
}
