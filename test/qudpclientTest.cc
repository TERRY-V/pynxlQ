#include "../core/qudpsocket.h"

using namespace niu;

int main(int argc, char** argv)
{
	QUdpClient quc;
	void* sock=NULL;

	int32_t ret=quc.init(sock, (char*)"192.168.146.128", 6543);
	if(ret<0) {
		Q_DEBUG("ret = %d", ret);
		return -1;
	}

	int32_t count=0;
	while(++count<100) {
		char buffer[1<<10]={0};
		snprintf(buffer, sizeof(buffer)-1, "^-^ %03d ......", count);

		char recv_buf[1024];
		int32_t recv_len=0;

		ret=quc.communicate(sock, buffer, strlen(buffer), recv_buf, sizeof(recv_buf), recv_len);
		if(ret<0) {
			Q_DEBUG("send ret = %d", ret);
			continue;
		}

		Q_DEBUG("recv: %.*s", recv_len, recv_buf);
	}

	Q_DEBUG("finished!");
	q_sleep(10000);

	return 0;
}
