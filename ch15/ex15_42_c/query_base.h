#pragma once
#include "textquery.h"
#include "queryresult.h"

class Query_base{
    friend class Query;
    protected:
        using line_no = TextQuery::line_no;
        virtual ~Query_base() = default;
    private:
        //eval 返回与当前query匹配的QueryResult
        virtual QueryResult eval(const TextQuery& ) const = 0;
        virtual std::string req()const = 0;
};
