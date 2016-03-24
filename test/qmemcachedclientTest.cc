#include "../sql/qmemcachedclient.h"

using namespace niu;

int main(int argc, char** argv)
{
	QMemcachedClient qmc;

	int32_t ret=qmc.init();
	if(ret) {
		Q_INFO("-1");
		return -1;
	}

	qmc.server_append("192.168.146.128", 11211);
	qmc.server_append("192.168.146.128", 11222);
	qmc.server_append("192.168.146.128", 11233);

	qmc.server_reset_all();

	char key[128]={0};
	char value[1<<10]={0};

	int32_t key_len=0;
	int32_t value_len=0;

#if 0
	int32_t count=0;
	while(++count) {
		printf("count = %d\n", count);

		snprintf(key, sizeof(key), "key%d", count);
		snprintf(value, sizeof(value), "value = %d", count);
		strcat(value, "tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt");
		strcat(value, "tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt");
		strcat(value, "tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt");
		strcat(value, "tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt");
		strcat(value, "tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt");

		key_len=strlen(key);
		value_len=strlen(value);

		ret=qmc.set_Key_Value(key, key_len, value, value_len);
		if(ret) {
			Q_INFO("-3");
			return -3;
		}

		char* result=NULL;
		int32_t result_len=0;
		ret=qmc.get_Key_Value(key, key_len, result, result_len);
		if(ret) {
			Q_INFO("ret = %d", ret);
		} else {
			printf("get: %s\n", result);
		}
	}
#else
	int32_t count=400000;
	while(++count) {
		printf("count = %d\n", count);

		snprintf(key, sizeof(key), "key%d", count);
		key_len=strlen(key);

		char* result=NULL;
		int32_t result_len=0;
		ret=qmc.get_Key_Value(key, key_len, result, result_len);
		if(ret) {
			Q_INFO("-4");
		} else {
			printf("get: %s\n", result);
		}
	}
#endif

#if 0
	ret=qmc.delete_Key(key, key_len);
	if(ret) {
		Q_INFO("-5");
		return -5;
	} else {
		printf("delete ok!\n");
	}
#endif

	return 0;
}
