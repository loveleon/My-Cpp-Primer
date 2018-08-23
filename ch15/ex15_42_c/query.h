#pragma once
#include "queryresult.h"
#include "query_base.h"
#include "wordquery.h"
#include <string>
#include <memory>

class Query;
std::ostream& print(std::ostream& out,const Query &q);
//class Query:public Query_base{
class Query{
    friend Query operator~(const Query&);
    friend Query operator&(const Query& , const Query&);
    friend Query operator|(const Query& , const Query&);
public:
    Query(const std::string &s):q(new WordQuery(s))
    {
        std::cout << "Query::Query(const std::string& s) where s="+s+"\n";
    }
    QueryResult eval(const TextQuery &t)const
    {
        auto rq = q->eval(t);
        return rq;
    }

    std::string req()const
    {
        std::cout << "Query::rep() \n";
       return  q->req();
    }

    private:
    Query(std::shared_ptr<Query_base> query):q(query)
    {
        std::cout << "Query::Query(std::shared_ptr<Query_base> query)\n";
    }
    std::shared_ptr<Query_base> q;
};
inline
std::ostream& print(std::ostream& out,const Query &q)
{
    out << q.req();
    return out;
}
