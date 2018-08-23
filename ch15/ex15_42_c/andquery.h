#pragma once
#include "query.h"
#include "binaryquery.h"

class And_Query:public Binary_Query{
    friend Query operator&(const Query &lft, const Query &rhs);
    And_Query(const Query& lft,const Query& rhs):Binary_Query(lft,rhs,"&")
    {
        std::cout << "AndQuery::AndQuery()\n";
    }

    //inherit req() and override eval
    virtual QueryResult eval(const TextQuery& t)const override;
};

inline Query operator&(const Query &lft, const Query &rhs)
{//Query WILL CALL twice.1.local Query 2.return value.
    std::cout << __func__ << std::endl;
    return std::shared_ptr<Query_base>(new And_Query(lft,rhs));
}
