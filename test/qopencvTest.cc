#include "../common/qopencv.h"

using namespace std;
using namespace niu;

int main(int argc, char** argv)
{
	int height, width;
	getImageSize("src1.jpg", &height, &width);
	cout<<height<<"*"<<width<<endl;
	return 0;
}
