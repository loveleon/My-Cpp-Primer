#pragma once
#include "query_base.h"
#include "query.h"

class Binary_Query:public Query_base{
protected:
    Binary_Query(const Query &l, const Query &r,std::string s):lhs(l),rhs(r),opSym(s){
        std::cout << "BinaryQuery::BinaryQuery()  where s=" + s + "\n";
    }
    Query lhs,rhs;
    std::string req()const {
        std::cout << "BinaryQuery::rep()\n";
        return "(" + lhs.req() +
            opSym +
            ")";
    }
    std::string opSym;
};
