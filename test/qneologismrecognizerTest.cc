#include "../common/qneologismrecognizer.h"

Q_USING_NAMESPACE

using namespace std;

int main()
{
	QNeologismRecognizer qnr;
	/*
	int ret=qnr.train("__common.lst");
	if(ret) {
		Q_DEBUG("qnr.train ret = (%d)", ret);
		return -1;
	}
	*/

	int ret=qnr.init("__htmprob.lib");
	if(ret) {
		Q_DEBUG("qnr.init ret = (%d)", ret);
		return -1;
	}

	QString text;
	text=text.readAll("__common.lst");

	std::list<QString> lines=text.line_tokenize();
	for(std::list<QString>::iterator it=lines.begin(); it!=lines.end(); ++it) {
		if(it->startsWith("$")) {
			QString line=it->mid(1, it->indexOf("<<", 2)-1);
			cout<<qnr.calculateWordProbability(line.c_str(), line.length()*2)<<'\t'<<line<<endl;
		}
	}

	/*
	QString data1="你好";
	cout<<qnr.calculateWordProbability(data1.c_str(), data1.length()*2)<<endl;

	QString data2="放马过来";
	cout<<qnr.calculateWordProbability(data2.c_str(), data2.length()*2)<<endl;
	*/

	return 0;
}
