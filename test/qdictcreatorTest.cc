#include "../common/qdictcreator.h"

Q_USING_NAMESPACE

int main(int argc, char** argv)
{
	int32_t ret=0;
	ret=QDictCreator::combine("__dict.common", "__dict.self");
	if(ret) {
		Q_INFO("combine ret = %d", ret);
		return EXIT_FAILURE;
	}

	ret=QDictCreator::pack("__common.lst", "__common.lib");
	if(ret) {
		Q_INFO("pack ret = %d", ret);
		return EXIT_FAILURE;
	}

	ret=QDictCreator::pack_pos("__common.lst", "__common.pos");
	if(ret) {
		Q_INFO("pack_pos ret = %d", ret);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
