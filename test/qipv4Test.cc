#include "../core/qipv4.h"

using namespace std;
using namespace niu;

int main(int argc, char** argv)
{
#if 1
	QIPv4Addr ip("192.168.146.128");
	QIPv4Peer ipaddr;
	ipaddr.set_ip(ip);
	ipaddr.set_port(80);
	cout<<ipaddr.get_ip().to_string()<<endl;
	cout<<ipaddr.get_host()<<endl;
#endif

#if 0
	QIPv4Peer ipaddr;
	ipaddr.set_host("www.baidu.com");
	ipaddr.set_port(80);
	cout<<ipaddr.get_ip().to_string()<<endl;
	cout<<ipaddr.get_host()<<endl;
#endif

	return 0;
}
