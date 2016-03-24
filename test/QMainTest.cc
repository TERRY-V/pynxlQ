#include "../common/qadjgraph.h"
#include "../common/qadlist.h"
#include "../common/qalgorithm.h"
#include "../common/qallocator.h"
#include "../common/qbitmap.h"
#include "../common/qbuffer.h"
#include "../common/qbytearray.h"
#include "../common/qchinesespelling.h"
#include "../common/qconfigreader.h"
#include "../common/qdatastream.h"
#include "../common/qdatetime.h"
#include "../common/qdenseindexmanager.h"
#include "../common/qdictcreator.h"
#include "../common/qdir.h"
//#include "../common/qdistance.h"
#include "../common/qfile.h"
#include "../common/qfunc.h"
#include "../common/qglobal.h"
#include "../common/qhashmap.h"
#include "../common/qhashsearch.h"
#include "../common/qheap.h"
#include "../common/qhttpclient.h"
#include "../common/qhttpserver.h"
#include "../common/qjaccardsimilarity.h"
#include "../common/qlbscheduler.h"
#include "../common/qipv4.h"
#include "../common/qlist.h"
#include "../common/qlogger.h"
#include "../common/qlogicalparser.h"
#include "../common/qmailsender.h"
#include "../common/qmarkovmodel.h"
#include "../common/qmemcachedclient.h"
#include "../common/qmd5.h"
#include "../common/qmd5file.h"
#include "../common/qmysqlclient.h"
#include "../common/qnetworkaccessmanager.h"
#include "../common/qobjectpool.h"
//#include "../common/qocrmanager.h"
#include "../common/qqueue.h"
#include "../common/qredblacktree.h"
#include "../common/qredisclient.h"
#include "../common/qregexp.h"
#include "../common/qremotemonitor.h"
#include "../common/qserialization.h"
#include "../common/qservice.h"
#include "../common/qstack.h"
#include "../common/qstoremanager.h"
#include "../common/qstridallocator.h"
#include "../common/qstring.h"
#include "../common/qtextcodec.h"
#include "../common/qtcpsocket.h"
#include "../common/qthread.h"
#include "../common/qtrietree.h"
#include "../common/qudpsocket.h"
#include "../common/qvector.h"
#include "../common/qzlibmanager.h"

Q_USING_NAMESPACE

// QClassCreator代码生成器类
class QClassCreator {
	public:
		// @函数名: QClassCreator构造函数和析构函数
		inline QClassCreator() {qd=QDate::now();}
		virtual ~QClassCreator() {}

		// @函数名: 设置C++ class类名
		void setClassName(const std::string& className)
		{mClassName=className;}

		// @函数名: 获取类名
		const std::string getClassName() const
		{return mClassName;}

		// @函数名: 设置当前类的作者
		void setAuthor(const std::string& author)
		{mAuthor=author;}

		// @函数名: 获取当前类的作者名
		const std::string getAuthor() const
		{return mAuthor;}

		// @函数名: 设置邮箱
		void setEmail(const std::string& email)
		{mEmail=email;}

		// @函数名: 获取邮箱
		const std::string getEmail() const
		{return mEmail;}

		// @函数名: 设置作者Blog相关信息
		void setBlog(const std::string& blog)
		{mBlog=blog;}

		// @函数名: 获取作者blog相关信息
		const std::string getBlog() const
		{return mBlog;}

		// @函数名: 代码产生器
		void process()
		{
			std::string fileName;
			fileName.append(q_to_lower(mClassName)).append(".h");

			std::string defString;
			defString.append("__").append(q_to_upper(mClassName)).append("_H_");

			if(QFile::exists(fileName.c_str())) {
				Q_INFO("BAD: file (%s) already exists!", fileName.c_str());
				return;
			}

			FILE* fp=fopen(fileName.c_str(), "w");
			Q_ASSERT(fp!=NULL, "QClassCreator: fopen (%s) error", fileName.c_str());

			// 创建程序文件头信息
			fprintf(fp, "/********************************************************************************************\n");
			fprintf(fp, "**\n");
			fprintf(fp, "** Copyright (C) 2010-2015 Terry Niu (Beijing, China)\n");
			fprintf(fp, "** Filename:	%s\n", fileName.c_str());
			fprintf(fp, "** Author:	%s\n", mAuthor.c_str());
			fprintf(fp, "** Email:	%s\n", mEmail.c_str());
			fprintf(fp, "** Support:	%s\n", mBlog.c_str());
			fprintf(fp, "** Date:	%s\n", qd.to_string(1).c_str());
			fprintf(fp, "**\n");
			fprintf(fp, "*********************************************************************************************/\n");

			// 创建程序代码信息
			fprintf(fp, "\n");
			fprintf(fp, "#ifndef %s\n", defString.c_str());
			fprintf(fp, "#define %s\n", defString.c_str());
			fprintf(fp, "\n");
			fprintf(fp, "#include \"qglobal.h\"\n");
			fprintf(fp, "\n");
			fprintf(fp, "Q_BEGIN_NAMESPACE\n");
			fprintf(fp, "\n");
			fprintf(fp, "class %s {\n", mClassName.c_str());
			fprintf(fp, "\tpublic:\n");
			fprintf(fp, "\t\tinline %s();\n", mClassName.c_str());
			fprintf(fp, "\n");
			fprintf(fp, "\t\tvirtual ~%s();\n", mClassName.c_str());
			fprintf(fp, "\n");
			fprintf(fp, "\tprivate:\n");
			fprintf(fp, "\n");
			fprintf(fp, "\tprotected:\n");
			fprintf(fp, "\n");
			fprintf(fp, "};\n");
			fprintf(fp, "\n");
			fprintf(fp, "Q_END_NAMESPACE\n");
			fprintf(fp, "\n");
			fprintf(fp, "#endif // %s\n", defString.c_str());

			// 打印成功日志
			Q_INFO("Congratulations! Class (%s) was created successfully!", mClassName.c_str());

			fclose(fp);
		}

	protected:
		// 日期类
		QDate qd;
		// 新类类名
		std::string mClassName;
		// 新类作者名
		std::string mAuthor;
		// 作者邮箱
		std::string mEmail;
		// 新类作者blog相关信息
		std::string mBlog;
};

int32_t main(int32_t argc, char** argv)
{
	if(argc!=2) {
		printf("Usage: ./qclasscreatorTest QNewClass\n");
		return EXIT_FAILURE;
	}

	QClassCreator qcc;
	qcc.setClassName(argv[1]);
	qcc.setAuthor("TERRY-V");
	qcc.setEmail("cnbj8607@163.com");
	qcc.setBlog("http://blog.sina.com.cn/terrynotes");

	qcc.process();

	return EXIT_SUCCESS;
}
