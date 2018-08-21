#pragma once
#include "queryresult.h"
#include "query_base.h"
#include "wordquery.h"
#include <string>
#include <memory>

class Query;
std::ostream& print(std::ostream& out,const Query &q);
class Query:public Query_base{
    friend Query operator~(const Query&);
    friend Query operator&(const Query& , const Query&);
    friend Query operator|(const Query& , const Query&);
public:
    Query(const std::string &s):q(new WordQuery(s))
    {
        std::cout << "Query::Query(const std::string& s) where s="+s+"\n";
    }
    virtual QueryResult eval(const TextQuery &t)const override
    {
        auto rq = q->eval(t);
        return rq;
    }

    virtual std::string req()const override
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
