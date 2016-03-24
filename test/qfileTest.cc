#include "../common/qfile.h"

using namespace niu;
using namespace std;

int main(int argc, char** argv)
{
	QFile file("word.txt");
	/*
	cout<<file.exists()<<endl;
	cout<<file.baseName()<<endl;
	cout<<file.rename("file.txt")<<endl;
	cout<<file.remove()<<endl;
	cout<<file.exists()<<endl;
	cout<<file.copy("my.txt")<<endl;

	cout<<file.file_name()<<endl;
	cout<<file.path()<<endl;
	cout<<file.baseName()<<endl;
	cout<<file.suffix()<<endl;

	cout<<file.fileMode()<<endl;
	*/

	if(!file.open("r")) {
		std::cerr<<file.errorString()<<endl;
		return -1;
	}

	vector<string> words;
	while(!file.atEnd()) {
		std::string line=file.readLine();
		words.push_back(line);
	}

	for(int i=0; i<words.size(); ++i)
	{
		for(int j=0; j<words.size(); ++j)
		{
			printf("%s%s\n", words[i].c_str(), words[j].c_str());
		}
	}

	/*
	std::cout<<QFile::hasdir("/server/kalava")<<std::endl;
	*/
	return 0;
}
