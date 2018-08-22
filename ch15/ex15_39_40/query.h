#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "textquery.h"

class Query_base{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;//used in eval function.
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery& t)const = 0;
    virtual std::string req()const = 0;
};

class WordQuery :public Query_base{
    friend class Query;
    WordQuery(const std::string& str):query_word(str)
    {
        std::cout << "WordQuery::WordQuery(" + str + ")\n";
    }
    virtual QueryResult eval(const TextQuery& t)const override {
        return t.query(query_word);
    }

    virtual std::string req()const override {
        std::cout << "WodQuery::rep()\n";
        return query_word;
    }

    std::string query_word;
};

/**
 * @brief interface class to manage Query_base inheritance.
 */
class Query {
    friend Query operator~(const Query &q);
    friend Query operator&(const Query& lft, const Query& rhs);
    friend Query operator|(const Query& lft, const Query& rhs);
public:
    Query(const std::string& str):q(new WordQuery(str))
    {
        std::cout << "Query::Query(const std::string& s) where s="+str+"\n";
    }

    QueryResult eval(const TextQuery& t)const {
        return q->eval(t);
    }

    std::string req()const {
        std::cout << "Query::rep() \n";
        return q->req();
    }

private:
    //constructor only for friend call.
    Query(std::shared_ptr<Query_base> query):q(query)
    {
        std::cout << "Query::Query(std::shared_ptr<Query_base> query)\n";
    }
    std::shared_ptr<Query_base> q;
};

inline std::ostream&
operator <<(std::ostream& out, const Query& q)
{
    //make a virtual call through its Query_base pointer
    out << q.req();
    return out;
}

class Binary_Query : public Query_base{
protected:
    Binary_Query(const Query& _lft, const Query& _rhs,std::string str):lft(_lft),rhs(_rhs),opSym(str)
    {
        std::cout << "BinaryQuery::BinaryQuery()  where s=" + str + "\n";
    }

    // @note abstract class Binary_Query doesn't define eval.
    std::string req()const {
        std::cout << "BinaryQuery::rep()\n";
        return "(" + lft.req() + " "
                   + opSym + " "
                + rhs.req() + ")";
    }

    Query lft,rhs;
    std::string opSym;
};

class OrQuery : public Binary_Query{
    friend Query operator|(const Query &lft, const Query &rhs);

    OrQuery(const Query& lft,const Query& rhs):Binary_Query(lft,rhs,"|"){
        std::cout << "OrQuery::OrQuery\n";
    }

    virtual QueryResult eval(const TextQuery& t)const override;
};

inline Query operator|(const Query &lft, const Query &rhs){
    return std::shared_ptr<Query_base>( new OrQuery(lft,rhs) );
}

class AndQuery : public Binary_Query{
    friend Query operator&(const Query &lft, const Query &rhs);

    AndQuery(const Query& lft,const Query& rhs):Binary_Query(lft,rhs,"&"){
        std::cout << "AndQuery::AndQuery\n";
    }

    virtual QueryResult eval(const TextQuery& t)const override;
};

inline Query operator&(const Query& lft, const Query& rhs){
    return std::shared_ptr<Query_base>(new AndQuery(lft,rhs));
}

class NotQuery:public Query_base{
    friend Query operator~(const Query& q);
    NotQuery(const Query& q):query(q){
        std::cout << "NotQuery::NotQuery()\n";
    }

    virtual std::string req()const override{
        std::cout << "NotQuery::rep()\n";
        return "~(" + query.req() + ")";
    }

    virtual QueryResult eval(const TextQuery& t)const override;
    Query query;
};

inline Query operator~(const Query& q)
{
    //explicit Query(std::shared_ptr<Query_base>) call.
    return std::shared_ptr<Query_base>(new NotQuery(q));
}
