#include "../common/qwordtokenizer.h"

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

	char sentence[]="国家 主席习近平11月1日向俄罗斯总统普京致慰问电，就俄罗斯一架客机在埃及西奈半岛失事向遇难者表示深切的哀悼，向遇难者亲属表示诚挚的慰问，表示值此俄罗斯人民悲伤的时刻，中国人民坚定同俄罗斯人民站在一起。";

	QStopwatch sw;
	sw.start();

	char dest[1<<20]={0};
	int len=strlen(sentence);
	ret=tokenizer->word_tokenize(sentence, len, dest, sizeof(dest));
	if(ret<0) {
		Q_INFO("tokenizer error, ret = (%d)", ret);
		return -2;
	}

	sw.stop();

	printf("consumed (%d) ms!\n", sw.elapsed_ms());
	printf("ret = (%d), dest_utf8 = (%.*s)\n", ret, ret, dest);

	delete tokenizer;
	tokenizer=NULL;

	return 0;
}
