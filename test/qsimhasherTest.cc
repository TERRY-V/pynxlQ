#include "../common/qsimhasher.h"
#include "../common/qfile.h"

using namespace niu;

std::string partOfString(const std::string& ss)
{
	if(ss.find("项目")!=ss.npos)
		return ss.substr(0, ss.find("项目")+6);

	if(ss.find("工程")!=ss.npos)
		return ss.substr(0, ss.find("工程")+6);

	return ss;
}

int main()
{
	std::string text=QFile::readAll("__sim.txt");
	std::vector<std::string> lines=q_line_tokenize(text);

	QSimHasher simhasher;
	int32_t topN=100;

	Q_ASSERT(simhasher.init()==0, "init error!");

	for(int i=0; i<lines.size(); ++i) {
		std::vector< std::pair<std::string, double> > wordWeights;
		uint64_t u64=0;

		simhasher.extract(partOfString(lines.at(i)), topN, wordWeights);
		simhasher.calculateSimHash(wordWeights, u64);

		std::cout<<"-----------------------"<<std::endl;
		std::cout<<lines[i]<<std::endl;
		simhasher.printKeyWords(wordWeights);
		std::cout<<u64<<std::endl;

		for(int j=0; j<lines.size(); ++j) {
			if(j==i) continue;

			std::vector< std::pair<std::string, double> > weights;
			uint64_t uhash=0;

			simhasher.extract(partOfString(lines.at(j)), topN, weights);
			simhasher.calculateSimHash(weights, uhash);

			if(QSimHasher::isEqual(u64, uhash, 8)) {
				std::cout<<lines[j]<<std::endl;
			}
		}
	}

	return 0;
}
