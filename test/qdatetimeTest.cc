#include <iostream>
#include "../common/qdatetime.h"

using namespace std;
using namespace niu;

int main()
{
	/*
#if 1
	//////////////////////////////////////////////////////////////////////
	QDate qd=QDate::now();

	cout<<"Year: "<<qd.year()<<endl;
	cout<<"Month: "<<qd.month()<<endl;
	cout<<"Day: "<<qd.day()<<endl;
	cout<<"Day of week: "<<qd.dayOfWeek()<<endl;
	cout<<"Day of year: "<<qd.dayOfYear()<<endl;
	cout<<"Days in month: "<<qd.daysInMonth()<<endl;
	cout<<"Days in year: "<<qd.daysInYear()<<endl;

	QDate qd_end(2016, 05, 31);
	for(QDate d=qd; d!=qd_end; d=d.addDays(1))
		cout<<d.to_string()<<endl;
	cout<<qd.daysTo(qd_end)<<endl;
#else
	/////////////////////////////////////////////////////////////////////
	QTime qt=QTime::now();
	QTime qt_dest(11, 22, 0);
	cout<<qt.secsTo(qt_dest)<<endl;

	cout<<"hour: "<<qt.hour()<<endl;
	cout<<"minute: "<<qt.minute()<<endl;
	cout<<"second: "<<qt.second()<<endl;
	cout<<"msec: "<<qt.msec()<<endl;
	cout<<qt.to_string()<<endl;

	sleep(3);
	cout<<qt.elapsed()<<endl;

	/////////////////////////////////////////////////////////////////////
	QDateTime qdt=QDateTime::now();
	//QDateTime qdt(1315802099);
	cout<<qdt.to_string(1)<<endl;
	cout<<qdt.date().to_string()<<endl;
	cout<<qdt.time().to_string()<<endl;

	cout<<QDateTime::timestamp()<<endl;
#endif
*/
	int nowVal=QDateTime::timestamp();
	nowVal+=60*60;

	QDateTime future(nowVal);
	std::cout<<future.to_string()<<std::endl;

	return 0;
}
