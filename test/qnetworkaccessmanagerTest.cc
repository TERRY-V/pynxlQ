#include <iostream>
#include "../include/qnetworkaccessmanager.h"
#include "../include/qtextcodec.h"
#include "../include/qfile.h"
#include "../include/qfunc.h"

using namespace std;
using namespace niu;

// 视图网
void testfotomore()
{
	QNetworkAccessManager *networkManager=new QNetworkAccessManager();
	if(networkManager->init()==-1) {
		cout<<"QNetworkAccessManager::init failed......"<<endl;
		return;
	}

	networkManager->setUserAgent();
	//networkManager->setCookieEnabled();
	networkManager->setRedirectionEnabled();

	//networkManager->setCookie("perpage=60; PHPSESSID=glpgr2pprm0m8b7am6jefajn45; _gat=1; Hm_lvt_3a06e9ed93d8a91cb70ffb26476e838a=1451901160; Hm_lpvt_3a06e9ed93d8a91cb70ffb26476e838a=1451901173; _ga=GA1.2.1386284207.1451901160; browsed_mid=isc129349434%3Bisc129392093%3Bisc129378345; Hm_lvt_e09a147d0763213db7bc57047f7ad31c=1451889777; Hm_lpvt_e09a147d0763213db7bc57047f7ad31c=1451901191; CNZZDATA1254085791=1865705173-1451887842-%7C1451901213");

	std::string url="http://fotomore.com/search/list.php";
	std::string data="mlt=0&searchurl=k%253D9358%2526&cachekey=k%253D9358%2526item%253D60%2526n%253D&perpage=60&page=5&datatype=1&ts=1451901257213";
	char login_content[1<<20]={0};

	networkManager->setReferer("http://fotomore.com/search/search.php?keyword=%E8%88%AA%E7%A9%BA");
	if(networkManager->doHttpPost(url.c_str(), data.c_str(), 10000, login_content, sizeof(login_content))<0) {
		printf("login failure......\n");
	} else {
		cout<<login_content<<endl;
	}

	delete networkManager;
	networkManager=NULL;
}

// 中国采购与招标网
void testChinaBidding()
{
	QNetworkAccessManager *networkManager=new QNetworkAccessManager();
	if(networkManager->init()==-1) {
		cout<<"QNetworkAccessManager::init failed......"<<endl;
		return;
	}

	networkManager->setUserAgent();
	networkManager->setCookieEnabled();
	networkManager->setRedirectionEnabled();

	// authcode
	std::string authcode_url="http://www.chinabidding.com.cn/cblcn/member.login/checkyzm";
	std::string authcode_data="randomID=56dac2c9-868b-45cb-a0c4-edc7e4829d78&yzm=iq9b&t=";
	char authcode_content[1<<20]={0};

	networkManager->setReferer("http://www.chinabidding.com.cn/");
	if(networkManager->doHttpPost(authcode_url.c_str(), authcode_data.c_str(), 10000, authcode_content, sizeof(authcode_content))<0) {
		printf("authcode failure......\n");
	} else {
		cout<<authcode_content<<endl;
	}

	// login
	std::string login_url="http://www.chinabidding.com.cn/cblcn/member.login/logincheck";
	std::string login_data="name=testaccount&password=3838438&url=";
	char login_content[1<<20]={0};

	networkManager->setReferer("http://www.chinabidding.com.cn/cblcn/member.login/login");
	if(networkManager->doHttpPost(login_url.c_str(), login_data.c_str(), 10000, login_content, sizeof(login_content))<0) {
		printf("login failure......\n");
	} else {
		cout<<login_content<<endl;
	}

	std::vector<std::string> urls;
	urls.push_back("http://www.chinabidding.com.cn/cblcn/infoshow/zbxx_print?record_id=CDZGD");
	urls.push_back("http://www.chinabidding.com.cn/cblcn/infoshow/zbxx_print?record_id=CDZFg");
	urls.push_back("http://www.chinabidding.com.cn/cblcn/infoshow/zbxx_print?record_id=qxmOH");
	urls.push_back("http://www.chinabidding.com.cn/cblcn/infoshow/zbxx_print?record_id=CDZ4t");
	urls.push_back("http://www.chinabidding.com.cn/cblcn/infoshow/zbxx_print?record_id=CDZNs");

	char content[1<<20]={0};

	networkManager->setReferer("http://www.chinabidding.com.cn/");

	for(int i=0; i<urls.size(); ++i)
	{
		if(networkManager->doHttpGet(urls[i].c_str(), 10000, content, sizeof(content))<0) {
			printf("bad......\n");
		} else {
			cout<<content<<endl;
		}
	}

	delete networkManager;
	networkManager=NULL;
}

void testURL()
{
	QNetworkAccessManager *networkManager=new QNetworkAccessManager();
	if(networkManager->init()==-1) {
		cout<<"QNetworkAccessManager::init failed......"<<endl;
		return;
	}

	char content[2<<20]={0};
	int32_t ret=0;

	networkManager->setUserAgent("Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36 MicroMessenger/6.5.2.501 NetType/WIFI WindowsWechat");
	ret=networkManager->doHttpGet("https://mp.weixin.qq.com/mp/getmasssendmsg?__biz=MzAxMDYwMTMzOQ==&uin=MTYyNjEyNTU2MA%3D%3D&key=7b81aac53bd2393dccb0092ebc490f57f4e460d1ecc86682bd8cdb3f4ec89c28c94971e7b7e73c75894c65a532f4e6486210bd3d8e4087ca&devicetype=Windows+7&version=62010025&lang=zh_CN&ascene=14&pass_ticket=VM8iOun8evce%2Fu3%2B152YPgL4Cj0%2BjxQ6%2FX8XOK8pN6eDS1ogKDOO8ki%2BfKM0JR8f&wx_header=1", 10000, content, sizeof(content));
	if(ret<0) {
		printf(" ==> (%d)\n", ret);
	} else {
		Q_INFO("RES = %.*s", ret, content);
	}
}

void testWeibo()
{
	QNetworkAccessManager *networkManager=new QNetworkAccessManager();
	if(networkManager->init()==-1) {
		cout<<"QNetworkAccessManager::init failed......"<<endl;
		return;
	}

	networkManager->setUserAgent();
	networkManager->setCookieEnabled();
	networkManager->setRedirectionEnabled();

	char content[1<<20]={0};
	int32_t ret=0;

#if 0
	ret=networkManager->doHttpGet("http://www.weibo.com/", 10000, content, sizeof(content));
	if(ret<0) {
		printf("doHttpGet failure......\n");
		abort();
	}
#endif

	networkManager->setReferer("http://d.weibo.com/1087030002_892_1001_1");
	//networkManager->setCookie("SUB=_2AkMhZO8Of8NjqwJRmPoTymzrZI1zzgHEiebDAHzsJxJjHlgX7AzhIt7PDz5bni-xR4ztHeW-H0ix; SUBP=0033WrSXqPxfM72-Ws9jqgMF55z29P9D9WW6C5Y2ZrOFDZD7Y9xOw_T9; login_sid_t=ba94d3b15b6ba904761c1b5474ba68f2; _s_tentry=passport.weibo.com; Apache=4041994351428.002.1446535178479; SINAGLOBAL=4041994351428.002.1446535178479; ULV=1446535178494:1:1:1:4041994351428.002.1446535178479:; YF-Page-G0=b9004652c3bb1711215bacc0d9b6f2b5");

	ret=networkManager->doHttpGet("http://d.weibo.com/1087030002_892_1001_1?ajaxpagelet=1&__ref=/1087030002_817&_t=FM_144653605683366", 10000, content, sizeof(content));
	if(ret<0) {
		printf("doHttpGet failure......\n");
		abort();
	}

	cout<<ret<<endl;
	cout<<content<<endl;
}

void testQichezhijia()
{
	QNetworkAccessManager *networkManager=new QNetworkAccessManager();
	if(networkManager->init()==-1) {
		cout<<"QNetworkAccessManager::init failed......"<<endl;
		return;
	}

	networkManager->setUserAgent();
	networkManager->setCookieEnabled();
	networkManager->setRedirectionEnabled();

	char content[1<<20]={0};
	int32_t ret=0;

#if 0
	ret=networkManager->doHttpGet("http://www.weibo.com/", 10000, content, sizeof(content));
	if(ret<0) {
		printf("doHttpGet failure......\n");
		abort();
	}
#endif

	//networkManager->setCookie("SUB=_2AkMhZO8Of8NjqwJRmPoTymzrZI1zzgHEiebDAHzsJxJjHlgX7AzhIt7PDz5bni-xR4ztHeW-H0ix; SUBP=0033WrSXqPxfM72-Ws9jqgMF55z29P9D9WW6C5Y2ZrOFDZD7Y9xOw_T9; login_sid_t=ba94d3b15b6ba904761c1b5474ba68f2; _s_tentry=passport.weibo.com; Apache=4041994351428.002.1446535178479; SINAGLOBAL=4041994351428.002.1446535178479; ULV=1446535178494:1:1:1:4041994351428.002.1446535178479:; YF-Page-G0=b9004652c3bb1711215bacc0d9b6f2b5");

	ret=networkManager->doHttpGet("http://newcar.xcar.com.cn/price/", 10000, content, sizeof(content));
	if(ret<0) {
		printf("doHttpGet failure......\n");
		abort();
	}

	cout<<ret<<endl;
	cout<<content<<endl;
}

int main(int argc, char** argv)
{
	//testChinaBidding();
	testURL();
	//testWeibo();
	//testQichezhijia();
	//testfotomore();
	return 0;
}
