#include<iostream>
#include<string>
#include<set>
#include<map>
#include"vectorTkit.h"

typedef std::set<std::string> SetStr;
typedef std::map<std::string, SetStr*> MapStrSetStr;
class DBConn
{
public:
	DBConn();
	~DBConn();
	void beginTxn() {}
	void endTxn() {}
	void  execSql(std::string& sql) {}
private:

};

DBConn::DBConn()
{
}

DBConn::~DBConn()
{
}
class SimpleTxnLog
{
public:
	SimpleTxnLog();
	~SimpleTxnLog();
	void addTxn(const std::string& id, const std::string& sql);
	void apply();
	void purge();

private:
	MapStrSetStr log_;
	DBConn* conn_;
};

SimpleTxnLog::SimpleTxnLog()
{
}

SimpleTxnLog::~SimpleTxnLog()
{
	//std::purge();
}
void SimpleTxnLog::addTxn(const std::string& id, const std::string& sql)
{
	SetStr* pSet = log_[id];
	if (pSet==NULL)
	{
		pSet = new SetStr();
		log_[id] = pSet;
	}
	pSet->insert(sql);
};
void SimpleTxnLog::apply()
{
	for (MapStrSetStr::iterator p = log_.begin(); p != log_.end(); p++)
	{
		conn_->beginTxn();

		for (SetStr::iterator pSql = p->second->begin(); pSql != p->second->begin(); pSql++)
		{
			std::string s = *pSql;
			conn_->execSql(s);
			std::cout << "Executing SQL: " << s << std::endl;
		}
		conn_->endTxn();
		delete p->second;
	}
	log_.clear();
}
void SimpleTxnLog::purge()
{
	for (MapStrSetStr::iterator p=log_.begin() ; p!=log_.end() ; p++)
	{
		delete p->second;
	}
	log_.clear();
}
int main(void)
{


	return 0;
}