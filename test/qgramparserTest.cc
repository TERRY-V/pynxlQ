#include "../common/qwordtokenizer.h"
#include "../common/qgramparser.h"

using namespace std;

Q_USING_NAMESPACE;

int main(int argc, char** argv)
{
	QWordTokenizer *tokenizer=new QWordTokenizer();
	Q_ASSERT(tokenizer!=NULL, "tokenizer is NULL!");

	int32_t ret=0;
	ret=tokenizer->init();
	if(ret<0) {
		Q_INFO("QWordTokenizer: init failed, ret = (%d)!", ret);
		return -1;
	}

	QGramParser gp;
	Q_ASSERT(gp.init()==0, "gp init error!");

	char sentence[]="山西大唐国际左云风电有限责任公司安全生产管理系统建设流标公示";

	QStopwatch sw;
	sw.start();

	char dest[1<<20]={0};
	ret=tokenizer->word_tokenize(sentence, strlen(sentence), dest, sizeof(dest));
	if(ret<0) {
		Q_INFO("tokenizer error, ret = (%d)", ret);
		return -2;
	}

	sw.stop();

	printf("Consumed (%d) ms!\n", sw.elapsed_ms());
	printf("Sentence = (%s)\n", sentence);

	std::cout<<"-----------------------------------"<<std::endl;
	printf("%.*s\n", ret, dest);

	std::list< std::vector<std::string> > listPOS;
	gp.str2listPOS(std::string(dest, ret), listPOS);

	gp.parse("PRE1", listPOS); 
	gp.parse("PRE2", listPOS); 
	gp.parse("COMP", listPOS); 
	gp.parse("ROLE", listPOS);

	std::cout<<"-----------------------------------"<<std::endl;
	for(std::list< std::vector<std::string> >::iterator it=listPOS.begin(); \
			it!=listPOS.end(); \
			++it)
	{
		std::cout<<"(";
		for(size_t i=0; i<it->size(); ++i)
		{
			std::cout<<it->at(i);
			if(i==0) std::cout<<">";
			else if(i!=it->size()-1) std::cout<<" ";
			else;
		}
		std::cout<<"),";
	}
	std::cout<<std::endl;

	delete tokenizer;
	tokenizer=NULL;

	return 0;
}
