#pragma once
#include "binaryquery.h"
#include "queryresult.h"

class OrQuery:public Binary_Query{
    friend Query operator|(const Query& lft, const Query &rhs);
    OrQuery(const Query& lft, const Query& rhs):Binary_Query(lft,rhs,"|"){
        std::cout << "OrQuery::OrQuery\n";
    }
    //inherit req() and override eval
    virtual QueryResult eval(const TextQuery& t)const override;
};

inline Query operator|(const Query& lft, const Query &rhs)
{
    std::cout << __func__ << std::endl;
    return std::shared_ptr<Query_base>(new OrQuery(lft,rhs));
}
