#include "../common/qstridallocator.h"

Q_USING_NAMESPACE

int main()
{
	QStrIDAllocator m_strid_allocator;
	int32_t ret=m_strid_allocator.init(10000, "__strid.lib");
	if(ret<0) {
		Q_DEBUG("init ret = (%d)\n", ret);
		return -1;
	}

	uint32_t id=0;
	ret=m_strid_allocator.str2id((char*)"牛小林", 9, id);
	if(ret<0) {
		Q_DEBUG("str2id ret = (%d)\n", ret);
		return -2;
	}
	Q_DEBUG("id = (%d)", id);

	ret=m_strid_allocator.str2id((char*)"裴营", 6, id);
	if(ret<0) {
		Q_DEBUG("str2id ret = (%d)\n", ret);
		return -2;
	}
	Q_DEBUG("id = (%d)", id);

	ret=m_strid_allocator.str2id((char*)"牛美涵", 9, id);
	if(ret<0) {
		Q_DEBUG("str2id ret = (%d)\n", ret);
		return -2;
	}
	Q_DEBUG("id = (%d)", id);

	ret=m_strid_allocator.str2id((char*)"裴营", 6, id);
	if(ret<0) {
		Q_DEBUG("str2id ret = (%d)\n", ret);
		return -2;
	}
	Q_DEBUG("id = (%d)", id);

	const char* str=NULL;
	uint32_t len=0;
	uint64_t md5;
	ret=m_strid_allocator.id2str(2, str, len, md5);
	if(ret<0) {
		Q_DEBUG("id2str ret = (%d)\n", ret);
		return -3;
	}

	Q_DEBUG("(%.*s) = (%lu)", len, str, md5);

	return 0;
}
