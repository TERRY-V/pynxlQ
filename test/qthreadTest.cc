#include "../core/qthread.h"
#include "../core/qnetworkaccessmanager.h"
#include "../core/qhttpclient.h"

using namespace std;
using namespace niu;

class JobThread: public QThread {
	public:
		JobThread(int32_t iid) :
			QThread(false),
			id(iid)
		{}

		virtual ~JobThread()
		{
			waitfor();
		}

	protected:
		int32_t id;

		virtual void execute()
		{
			QNetworkAccessManager *networkManager=new QNetworkAccessManager();
			if(networkManager->init()==-1) {
				cout<<"QNetworkAccessManager::init failed......"<<endl;
				abort();
			}

			// 有道词典数据采集
			networkManager->resetOption();
			networkManager->setUserAgent();
			networkManager->setRedirectionEnabled();

			bool quit(false);
			char buf[100*1024]={0};

			int32_t count=0;

			while(!quit) {
				cout<<"Thread "<<id<<" ("<<++count<<")......"<<endl;
#if 1
				//int ret=networkManager->doHttpGet("http://www.chinabidding.com.cn/search/searchzbw/search2?keywords=&areaid=&categoryid=&b_date=month", buf, sizeof(buf));
				//int ret=networkManager->doHttpGet("http://pic9.zhongsou.com/zfsimage/1df26349f417d6ef", buf, sizeof(buf), 3000);
				int ret=networkManager->doHttpGet("http://192.168.146.128:8088/", buf, sizeof(buf), 10000);
				//int ret=networkManager->doHttpHeader("http://www.chinabidding.com/", buf, sizeof(buf));
				//int ret=networkManager->doHttpGet("http://www.baidu.com", buf, sizeof(buf));
				if(ret<0) {
					printf("bad......\n");
				} else {
					cout<<buf<<endl;
				}
#else

				QHttpRequestHeader request_header;
				//request_header.setURL("http://blog.sina.com.cn/s/blog_74a7e56e0102v7zf.html");
				request_header.setURL("http://192.168.1.226:8088/");

				QHttpClient qhr;
				int32_t ret=qhr.request(request_header, buf, sizeof(buf));
				if(ret<0) {
					Q_INFO("ret = %d", ret);
					continue;
				}

				printf("ret = (%d)\n", ret);
				printf("out = (%.*s)\n", ret, buf);
#endif
			}
		}
};

int main(int argc, char** argv)
{
	int32_t max_threads=1;
	for(int32_t i=0; i<max_threads; ++i) {
		JobThread* j=new JobThread(i+1);
		j->start();
	}

	q_serve_forever();

	return 0;
}
