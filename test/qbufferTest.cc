#include "../core/qbuffer.h"

using namespace std;
using namespace niu;

int main(int argc, char** argv)
{
	QBuffer buffer;
	buffer.expand(1048);

	cout<<buffer.pour(1000)<<endl;
	cout<<buffer.drain(800)<<endl;
	cout<<buffer.strip(200)<<endl;

	cout<<buffer.get_data_length()<<endl;
	cout<<buffer.get_free_length()<<endl;
	cout<<buffer.get_buf_length()<<endl;
	return 0;
}
