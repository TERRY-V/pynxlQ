#include <iostream>
#include "qmarkovmodel.h"

int main(int argc, char** argv)
{
	QMarkovModel* qmm=new QMarkovModel();
	assert(qmm!=NULL);

	// 状态转移矩阵概率二维数组
	// 假设: 状态S0:名词; 状态S1:动词; 状态S2:形容词
	double prob[][3]={{0.3, 0.5, 0.2}, {0.5, 0.3, 0.2}, {0.4, 0.2, 0.4}};

	int32_t ret=qmm->init(&prob[0][0], 3);
	if(ret) {
		Q_DEBUG("QMarkovModel::init ret = (%d)", ret);
		return -1;
	}

	qmm->printStateTransitionMatrix();

	// 句子序列: 假设某段文字的首个词是名词, 计算序列(名词->动词->形容词->名词)的概率
	int32_t posSequence1[4]={0, 1, 2, 0};
	double prob_seq1=qmm->getSequenceProbability(posSequence1, sizeof(posSequence1)/sizeof(int32_t));
	printf("名->动->形->名: prob_seq1 = %lf\n", prob_seq1);

	// 句子序列: 假设某段文字的首个词是名词, 计算序列(名词->名词->名词->名词)的概率
	int32_t posSequence2[4]={0, 0, 0, 0};
	double prob_seq2=qmm->getSequenceProbability(posSequence2, sizeof(posSequence2)/sizeof(int32_t));
	printf("名->名->名->名: prob_seq2 = %lf\n", prob_seq2);

	return 0;
}
