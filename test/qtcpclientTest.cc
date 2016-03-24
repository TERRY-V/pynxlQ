#include "../common/qtcpsocket.h"

Q_USING_NAMESPACE

int main()
{
	QTcpClient client;
	void* sock=NULL;

	char send_buf[1024]={0};
	int32_t send_len=0;

	char* ptr_temp=send_buf;
	*(uint64_t*)ptr_temp=TCP_HEADER_VERSION;
	*(int32_t*)(ptr_temp+8)=39;
	*(uint16_t*)(ptr_temp+12)=1;
	*(uint16_t*)(ptr_temp+14)=1;
	*(uint16_t*)(ptr_temp+30)=1;
	*(uint16_t*)(ptr_temp+32)=1;
	*(int32_t*)(ptr_temp+34)=13;
	memcpy(ptr_temp+38, "Hello, world!", 13);
	send_len=51;

	char recv_buf[1024]={0};
	int32_t recv_len=49;

	int32_t count=0;
	int32_t ret=0;

	//////////////////////////////////////////////////////////////////////

	QStopwatch sw;
	sw.start();
	while(count<100) {
		++ count;

		ret=client.connect(sock);
		if(ret<0) {
			Q_INFO("Connect error!");
			return -1;
		}

		ret=client.send(sock, send_buf, send_len);
		if(ret<0) {
			Q_INFO("Send error!");
			return -2;
		}

		ret=client.recv(sock, recv_buf, recv_len);
		if(ret<0) {
			Q_INFO("Recv error!");
			return -3;
		}

		//printf("Count = (%d), Code = (%d), Reply = (%.*s)\n", count, *(int32_t*)(recv_buf+28), 13, recv_buf+36);

		client.close(sock);
	}
	sw.stop();
	printf("consumed time = (%d)\n", sw.elapsed_ms());

	return 0;
}
