#pragma once
#include "query_base.h"
#include "query.h"

class NotQuery:public Query_base{
    friend Query operator~(const Query &q);
    NotQuery(const Query &q):query(q){
        std::cout << "NotQuery::NotQuery()\n";
    }
    virtual std::string req()const override
    {
        std::cout << "NotQuery::rep()\n";
        return "~(" + query.req() + ")";
    }
    virtual QueryResult eval(const TextQuery& t)const override;
    Query query;
};
inline Query operator~(const Query &t)
{
    std::cout << __func__ << std::endl;
   return std::shared_ptr<Query_base>(new NotQuery(t));
}
