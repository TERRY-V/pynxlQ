#include "../common/qadjgraph.h"
#include "../common/qstring.h"

Q_USING_NAMESPACE

int main(int argc, char** argv)
{
	QString str="您好棒，周杰伦";
	QAdjGraph<QString> *adjGraph=new QAdjGraph<QString>(str.length()+1);

	Token<QString> token;
	for(int i=0; i<str.length(); ++i)
		adjGraph->insertEdge(i, i+1, token);
	adjGraph->insertEdge(0, 2, token);
	adjGraph->insertEdge(1, 3, token);
	adjGraph->insertEdge(4, 7, token);
	adjGraph->insertEdge(5, 7, token);

	adjGraph->printGraph();
	std::vector<int32_t> vec=adjGraph->Dijkstra(0, str.length());
	for(std::vector<int32_t>::iterator it=vec.begin(); it!=vec.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;

	delete adjGraph;
	return 0;
}
