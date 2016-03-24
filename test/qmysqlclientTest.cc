#include <iostream>
#include "../common/qmysqlclient.h"

using namespace std;
using namespace sql;
using namespace niu;

void testMysqlClient()
{
	// 创建数据库连接池
	QMySQLClient *connPool=QMySQLClient::getInstance("tcp://111.206.69.170:3306", "kaifa", "L1e27dNp");
	Connection* conn=connPool->getConnection();

	// 创建一次连接
	Statement *stmt=conn->createStatement();
	stmt->execute("use comsystem");

#if 0
	// select............
	PreparedStatement *pstmt=conn->prepareStatement("SELECT title FROM video3_3.variety WHERE title like ? AND srcsite = ?");
	//PreparedStatement *pstmt=conn->prepareStatement("SELECT title FROM video3_3.variety WHERE title like ?");
	pstmt->setString(1, '%'+string("笑傲江湖")+'%');
	pstmt->setString(2, "迅雷看看");
	ResultSet* res=pstmt->executeQuery();
	std::cout<<res->rowsCount()<<endl;
	while(res->next()) {
		cout<<res->getString(1)<<endl;
	}

	// insert.............
	PreparedStatement* pstmt=conn->prepareStatement("INSERT INTO maes_proj_real(projname, type, creationtime, opid) \
			VALUES(?, ?, now(), ?)");
	pstmt->setString(1, line);
	pstmt->setInt(2, 1);
	pstmt->setString(3, "niuxl");
	pstmt->executeUpdate();
	delete pstmt;
	}
#endif

	// 待写入标准表的字段
	int32_t pid;
	std::string name;
	int32_t related_id;
	std::string related_name;
	std::string relationship;

	for(int32_t i=10000; i<=10000; ++i) {
		// 读取每个PID的关系信息数据
		PreparedStatement *pstmt=conn->prepareStatement("SELECT prr.base_pid, "\
				"IF(char_length(pfmr.name), pfmr.name, " \
				"(SELECT pfcr.name " \
				"FROM people_father_collect_relationship AS pfcr, people_relation_relationship AS prr " \
				"WHERE pfcr.lid = prr.lid)), "\
				"pcmr.related_id, "\
				"IF(char_length(pcmr.related_name), pcmr.related_name, " \
				"(SELECT related_name " \
				"FROM people_children_collect_relationship AS pccr " \
				"WHERE pccr.related_id = pcmr.related_id)), " \
				"IF(char_length(pcmr.relationship), pcmr.relationship, " \
				"(SELECT relationship " \
				"FROM people_children_collect_relationship AS pccr " \
				"WHERE pccr.related_id = pcmr.related_id)) " \
				"FROM people_relation_relationship AS prr, people_father_man_relationship AS pfmr, " \
				"people_children_man_relationship AS pcmr " \
				"WHERE prr.base_pid = ? AND prr.base_pid = pfmr.pid AND prr.pn_key = pcmr.pn_key;");
		pstmt->setInt(1, i);
		ResultSet* res=pstmt->executeQuery();

		Q_INFO("res->rowsCount()=(%d)", res->rowsCount());

		while(res->next()) {
			// 依次获取每条关系
			pid=res->getInt(1);
			name=res->getString(2);
			related_id=res->getInt(3);
			related_name=res->getString(4);
			relationship=res->getString(5);

			Q_INFO("PID=(%d)\tname=(%s)\trelated_id=(%d)\trelated_name=(%s)\trelationship=(%s)", \
					pid, name.c_str(), related_id, related_name.c_str(), relationship.c_str());

#if 0
			__process();
#endif

			// 将获取的关系插入标准表
			PreparedStatement* pstmt1=conn->prepareStatement("INSERT INTO people_final_relationship(pid, name, " \
					"related_id, related_name, relationship, create_time) " \
					"VALUES(?, ?, ?, ?, ?, now())");
			pstmt1->setInt(1, pid);
			pstmt1->setString(2, name);
			pstmt1->setInt(3, related_id);
			pstmt1->setString(4, related_name);
			pstmt1->setString(5, relationship);
			pstmt1->executeUpdate();

			delete pstmt1;
			pstmt1=NULL;
		}

		delete pstmt;
		pstmt=NULL;
	}

	// 释放本次连接
	connPool->releaseConnection(conn);
}

void displayTree(Connection* conn, int id)
{
	// 读取每个PID的关系信息数据
	PreparedStatement *pstmt=conn->prepareStatement("SELECT synsetid, pid, words FROM image_net WHERE pid = ?;");
	pstmt->setInt(1, id);

	ResultSet* res=pstmt->executeQuery();
	while(res->next()) {
		int synsetid=res->getInt(1);
		int pid=res->getInt(2);
		std::string words=res->getString(3);
		printf("%d\t%s\n", synsetid, words.c_str());
		displayTree(conn, synsetid);
	}

	delete pstmt;
	pstmt=NULL;
}

void testTree()
{
	// 创建数据库连接池
	QMySQLClient *connPool=QMySQLClient::getInstance("tcp://118.26.166.115:3306", "platformDC_admin", "16AlrnblL");
	Connection* conn=connPool->getConnection();

	// 创建一次连接
	Statement *stmt=conn->createStatement();
	stmt->execute("use platformDC");

	int id=0;
	displayTree(conn, id);
}

int main(int argc, char** argv)
{
	testTree();
	return 0;
}
