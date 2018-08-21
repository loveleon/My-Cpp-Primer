#pragma once
#include "query_base.h"
#include "query.h"
//���в���ͨ��Query
class WordQuery:public Query_base {
    friend Query;
    WordQuery(const std::string& s):query_word(s){
        std::cout << "WordQuery::WordQuery(" + s + ")\n";
    }

    virtual QueryResult eval(const TextQuery& t)const override
    {
        return t.query(query_word);
    }

    virtual std::string req()const override{
        std::cout <<"WordQuery::req()\n";
        return query_word;
    }

    std::string query_word;
};
