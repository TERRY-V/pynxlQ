#include "../common/qfunc.h"
#include "../common/qtextcodec.h"

using namespace std;
using namespace niu;

int main(int argc, char** argv)
{
	//double ls=q_to_money("100万");
	//std::cout<<ls<<std::endl;

	//char src[100]={0};
	//unsigned long long i=30000000000000000;
	//q_to_str(i, src);
	//cout<<src<<endl;
	//cout<<q_to_string(src)<<endl;
	//
	//string ss="设摊夏洛克  第三季度";
	//cout<<q_simplified(ss)<<endl;

	/*
	char str[]="步步惊心|||3D版|||bubu|||jingxin";
	char *p=str;
	char sep[]="|||";

	int pos[10];
	int n=q_split(str, 30, sep, strlen(sep), pos, sizeof(pos)/sizeof(int));
	cout<<"Original str: "<<str<<endl;
	cout<<"Number splitted: "<<n<<endl;
	for(int i=0; i<n; ++i)
		printf("(%02d): [%02d:%02d] %.*s\n", i, pos[2*i], pos[2*i+1], pos[2*i+1]-pos[2*i], p+pos[2*i]);
	*/
	//char *dest[128];
	//int n=q_split(str, strlen(str), sep, strlen(sep), dest);
	//cout<<"Number splitted: "<<n<<endl;
	//for(int i=0; i<n; ++i) {
	//	cout<<i<<'\t'<<dest[i]<<'\t'<<strlen(dest[i])<<endl;
	//}
	
	//char src[]="3D步步惊心 3D版 bu3Dbu jingxin3D";
	//cout<<q_find_first_of(src, strlen(src), 'b')<<endl;
	//cout<<q_find_last_of(src, strlen(src), 'b')<<endl;
	//cout<<q_find(src, strlen(src), "bu3D", 4)<<endl;
	//int32_t next[100];
	//q_next_KMP(src, strlen(src), next);
	//cout<<q_find_KMP(src, strlen(src), "bu3D", 4, next)<<endl;

	//cout<<q_strchr(src, strlen(src), 'b')<<endl;
	//char *c=q_strstr(src, strlen(src), "3D", 2);
	//char *beg=src;
	//char *pbeg=NULL;
	//char *pend=NULL;
	
	//char dest[1024];
	//int srclen=strlen(src);
	//int ret=q_strrep(src, srclen, (char*)"3D", 2, (char*)"sss", 3, dest, 40);
	//printf("%.*s\n", ret, dest);
	//cout<<ret<<endl;
	
	/*
	char dest[100];
	int ret=q_to_str(UINT32(3123456789), dest);
	printf("%d\n", ret);
	printf("%.*s\n", ret, dest);
	*/

	/*
	std::string text="你好！我们?可以做？彭门户。萨顶顶!";
	std::list<std::string> sents=q_sent_tokenize(text);
	for(std::list<std::string>::iterator it=sents.begin(); it!=sents.end(); ++it)
		cout<<*it<<endl;
	*/

	/*
	char src[]="sdj<![CDATA[ddd]]>dsssdddddddd";
	char search[]="sss";
	char replace[]="bb";

	int srclen=strlen(src);
	int searchlen=strlen(search);
	int replacelen=strlen(replace);

	int32_t ret=q_strrep_in_place(src, srclen, search, searchlen, replace, replacelen);
	if(ret<0) {
		Q_DEBUG("ret = %d", ret);
		return -1;
	} else {
		Q_DEBUG("ret = %d", ret);
		Q_DEBUG("src = %.*s", ret, src);
	}

	int32_t ret=q_strdel(src, srclen, search, searchlen);
	if(ret<0) {
		Q_INFO("ret = %d", ret);
		return -1;
	} else {
		Q_INFO("ret = %d", ret);
		Q_INFO("src = %.*s", ret, src);
	}

	int ret=q_strdel_cdata(src, srclen);
	if(ret<0) {
		Q_INFO("ret = %d", ret);
		return -1;
	} else {
		Q_INFO("ret = %d", ret);
		Q_INFO("src = %.*s", ret, src);
	}
	*/

	/*
	char src[]="我【（是）】？真的　真的很。爱你哦！";
	int len=strlen(src);
	INT32 ret=q_normalize(src, len);
	Q_DEBUG("ret = %d", ret);
	Q_DEBUG("%.*s", ret, src);
	
	printf("%d\n", q_to_num((char*)"123456789", 9));
	printf("%d\n", q_to_num((char*)"一二三肆五", 15));
	printf("%d\n", q_to_num((char*)"一, 2, 3, 4, 5", 15));
	printf("%d\n", q_to_num((char*)"两百五十一", 15));
	printf("%d\n", q_to_num((char*)"二百五十", 12));
	printf("%d\n", q_to_num((char*)"二五零", 9));
	printf("%d\n", q_to_num((char*)"二", 3));
	printf("%d\n", q_to_num((char*)"二百零五", 12));
	printf("%d\n", q_to_num((char*)"2零五", 7));
	printf("%d\n", q_to_num((char*)"十五万", 9));
	printf("%d\n", q_to_num((char*)"二百二十万", 15));
	printf("%d\n", q_to_num((char*)"百二十三", 12));
	printf("%d\n", q_to_num((char*)"二百五", 9));

	*/
	//const std::string ss="sss<title>111</title><title>122211</title>";
	//std::string s=q_substr(ss, "<title>", "</title>");
	//std::cout<<s<<std::endl;

	/*
	char src[]="&nbsp;v群群号：100489824（加群需要全订阅或粉丝值三千）YY：4095";
	int len=strlen(src);
	char dest[10240]={0};

	int dest_len=q_denoise(src, len, dest, sizeof(dest));
	Q_DEBUG("dest_len = (%d)", dest_len);
	Q_DEBUG("dest = (%.*s)", dest_len, dest);

	char src1[]="%E5%BD%95%E5%83%8F0001";
	int len1=strlen(src1);
	char dest1[1024]={0};

	int dest1_len=q_url_decode(src1, len1, dest1, 12);
	cout<<dest1_len<<'\t'<<dest1<<endl;

	char src2[5]="";
	char* p2=src2;
	*(int32_t*)p2=0xFAC9CBC8;
	int len2=strlen(src2);
	char dest2[1024]={0};

	int dest2_len=q_url_encode(src2, len2, dest2, sizeof(dest2));
	cout<<dest2_len<<'\t'<<dest2<<endl;
	*/

	/*
	char src[]="你好试试试试SSSsssSSS";
	char* p=src;
	cout<<q_to_lower(p)<<endl;
	cout<<q_to_upper(p)<<endl;
	*/

	/*
	cout<<q_format_byte_size(1024*1024*1024)<<endl;

	char src[]="\t   \t";
	cout<<murmurHash((void*)src, strlen(src))<<endl;

	char* p=q_trim(src, strlen(src));
	if(p==NULL) {
		cout<<"null"<<endl;
		return -1;
	} else {
		cout<<strlen(p)<<'\t'<<p<<endl;
	}
	*/

	/*
	for(uint64_t i=10000000000; i<10000000100; ++i) {
		std::cout<<q_id_to_62string(i)<<'\t';
		std::cout<<q_62string_to_id(q_id_to_62string(i))<<std::endl;
	}

	void* handle=NULL;
	char fileName[1024];

	cout<<q_dir_open(handle, "../core")<<endl;
	while(q_dir_travel(handle, fileName)==0)
		cout<<fileName<<endl;
	cout<<q_dir_close(handle)<<endl;

	cout<<q_get_local_ip()<<endl;
	*/

	//std::cout<<murmurHash64A((void*)"hello", 5, 0xadc83b19ULL)<<std::endl;

	//char src1[]="\\u8303\\u51b0\\u51b0";
#if 0
	char src1[]="Angelababy";
	int len1=strlen(src1);
	char dest1[1024]={0};

	int dest1_len=q_unicode_hex_decode(src1, len1, dest1, 12);
	cout<<dest1_len<<'\t'<<dest1<<endl;

	char buf[1024]={0};
	int len=QTextCodec::unicode2utf8(dest1, dest1_len, buf, sizeof(buf));
	cout<<buf<<len<<endl;

	cout<<q_is_url("http://www.baidu.com")<<endl;
	cout<<q_repair_url("//item.jd.com/11111.html")<<endl;
	cout<<q_repair_url("://item.jd.com/11111.html")<<endl;
	cout<<q_repair_url("item.jd.com/11111.html")<<endl;
	cout<<q_repair_url("/11111.html")<<endl;
	cout<<q_repair_url("http://www.host.com/11111.html")<<endl;
	cout<<q_repair_url("http:\\/\\/slide.sky.news.sina.com.cn\\/slide_33_70549_38507.html")<<endl;
#endif

	char str[]="abcbae";
	//q_full_permutation(str, 1, 4);
	cout<<q_is_palindrome(str, 6)<<endl;

	return 0;
}
