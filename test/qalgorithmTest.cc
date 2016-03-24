#include  "../core/qalgorithm.h"

using namespace std;
using namespace niu;

typedef struct __person_info {
	int id;
	char name[30];

	__person_info()
	{}

	__person_info(int __id, char* __str) {
		id=__id;
		strcpy(name, __str);
	}

	bool operator>(const __person_info& __pi)
	{return id>__pi.id;}

	bool operator<(const __person_info& __pi)
	{return id<__pi.id;}

	bool operator>=(const __person_info& __pi)
	{return id>=__pi.id;}

	bool operator<=(const __person_info& __pi)
	{return id<=__pi.id;}

	bool operator==(const __person_info& __pi)
	{return id==__pi.id;}
} PERSON_INFO;

int compare(char* p1, char* p2)
{
	return strcmp(p1, p2);
}

int main(int argc, char** argv)
{
	cout<<"Test binary search......"<<endl;
	uint64_t queryID[]={25, 36, 76, 88, 126, 158, 139};
	cout<<Q_Binary_Search_Default<uint64_t>(0, 6, queryID, 126)<<endl;
	cout<<Q_Binary_Search_Custom<uint64_t>(0, 6, queryID, 126)<<endl;
	cout<<Q_Binary_Search_Recursion<uint64_t>(0, 6, queryID, 87)<<endl;

	cout<<"Test basic sort......"<<endl;
	vector<PERSON_INFO> vec, vec1;
	vec.push_back(PERSON_INFO(56, (char*)"niuxl"));
	vec.push_back(PERSON_INFO(48, (char*)"suping"));
	vec.push_back(PERSON_INFO(32, (char*)"wangjin"));
	vec.push_back(PERSON_INFO(89, (char*)"zhangkun"));
	vec.push_back(PERSON_INFO(75, (char*)"peiying"));
	vec.push_back(PERSON_INFO(66, (char*)"peishengnan"));
	vec.push_back(PERSON_INFO(18, (char*)"wangcong"));
	vec.push_back(PERSON_INFO(21, (char*)"rongxj"));
	vec.push_back(PERSON_INFO(35, (char*)"zhangbz"));
	vec.push_back(PERSON_INFO(34, (char*)"wangzp"));
	vec.push_back(PERSON_INFO(86, (char*)"sunjj"));
	vec.push_back(PERSON_INFO(11, (char*)"wangf"));
	vec.push_back(PERSON_INFO(18, (char*)"wangf"));
	vec.push_back(PERSON_INFO(23, (char*)"zhangsan"));
	vec.push_back(PERSON_INFO(89, (char*)"lisi"));
	vec.push_back(PERSON_INFO(06, (char*)"wangw"));
	vec.push_back(PERSON_INFO(22, (char*)"zhangk"));
	vec.push_back(PERSON_INFO(99, (char*)"yajing"));
	vec.push_back(PERSON_INFO(54, (char*)"yany"));
	vec.push_back(PERSON_INFO(56, (char*)"wajun"));
	vec.push_back(PERSON_INFO(73, (char*)"guanj"));
	vec.push_back(PERSON_INFO(92, (char*)"yues"));
	vec.push_back(PERSON_INFO(27, (char*)"malei"));
	
	vec1.resize(vec.size());

	cout<<"original vec:"<<endl;
	for(size_t i=0; i<vec.size(); ++i)
		cout<<vec[i].id<<'\t'<<vec[i].name<<endl;
	cout<<endl;

	//Q_Bubble_Sort_Improved(&vec[0], 0, vec.size()-1);
	//Q_Insert_Sort(&vec[0], 0, vec.size()-1);
	//Q_Shell_Sort(&vec[0], 0, vec.size()-1);
	//Q_Quick_Sort(&vec[0], 0, vec.size()-1);
	Q_Quick_Sort_3(&vec[0], 0, vec.size()-1);
	//Q_Merge_Sort(&vec[0], &vec1[0], 0, vec.size()-1);
	//Q_Heap_Sort(&vec[0], vec.size());

	cout<<"sorted vec:"<<endl;
	for(size_t i=0; i<vec.size(); ++i)
		cout<<vec[i].id<<'\t'<<vec[i].name<<endl;
	cout<<endl;

	cout<<"Test multi key sort......"<<endl;

	int key1[]={56, 48, 48, 48, 75, 66, 18, 21};
	char* key2[]={"niuxl", "sup", "anj", "zhangk", "peiy", "peisn", "wangzp", "rongxj"};
	int key3[]={1986, 1988, 1978, 1977, 1983, 1988, 1985, 1982};
	int key4[]={88, 56, 32, 76, 38, 89, 100, 65};
	char* key5[]={"nxl", "sp", "wj", "zk", "py", "psn", "wzp", "rxj"};

	//Q_Recursion_1K<int>(0, 7, key1);
	Q_Recursion_1K_Custom<int>(0, 7, key1);
	//Q_Unrecursion_1K<int>(0, 7, key1);
	//Q_Recursion_1K_1P<int, char*>(0, 7, key1, key2);
	//Q_Unrecursion_1K_1P<int, char*>(0, 7, key1, key2);
	//Q_Recursion_1K_2P<int, char*, int>(0, 7, key1, key2, key3);
	//Q_Unrecursion_1K_2P<int, char*, int>(0, 7, key1, key2, key3);
	//Q_Recursion_1K_3P<int, char*, int, int>(0, 7, key1, key2, key3, key4);
	//Q_Unrecursion_1K_3P<int, char*, int, int>(0, 7, key1, key2, key3, key4);
	//Q_Recursion_2K<int, char*>(0, 7, key1, key2);
	//Q_Unrecursion_2K<int, char*>(0, 7, key1, key2);
	//Q_Recursion_2K_1P<int, char*, int>(0, 7, key1, key2, key3);
	//Q_Unrecursion_2K_1P<int, char*, int>(0, 7, key1, key2, key3);
	//Q_Recursion_2K_2P<int, char*, int, int>(0, 7, key1, key2, key3, key4);
	//Q_Unrecursion_2K_2P<int, char*, int, int>(0, 7, key1, key2, key3, key4);
	//Q_Recursion_2K_3P<int, char*, int, int, char*>(0, 7, key1, key2, key3, key4, key5);
	//Q_Unrecursion_2K_3P<int, char*, int, int, char*>(0, 7, key1, key2, key3, key4, key5);
	//Q_Recursion_3K_1P<int, char*, int, int>(0, 7, key1, key2, key3, key4);
	//Q_Unrecursion_3K_1P<int, char*, int, int>(0, 7, key1, key2, key3, key4);
	//Q_Recursion_3K_2P<int, char*, int, int, char*>(0, 7, key1, key2, key3, key4, key5);
	//Q_Unrecursion_3K_2P<int, char*, int, int, char*>(0, 7, key1, key2, key3, key4, key5);

#if 0
	QQSParallel<int> qsp;
	cout<<qsp.init()<<endl;
	cout<<qsp.quick_sort(0, 7, key1)<<endl;
#endif

	cout<<"after sorted:"<<endl;
	for(int i=0; i!=8; ++i)
		cout<<key1[i]<<'\t'<<key2[i]<<'\t'<<key3[i]<<'\t'<<key4[i]<<'\t'<<key5[i]<<endl;

	return 0;
}
