#include <algorithm>
#include "query.h"

/**
 * @brief AndQuery::eval
 */
QueryResult AndQuery::eval(const TextQuery& t)const {
    //Query::eval will call virtual eval .
    QueryResult left = lft.eval(t),right = rhs.eval(t);

    std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();


    std::set_intersection(left.begin(),left.end(),
                        right.begin(),right.end(),
                        std::inserter(*ret_lines,ret_lines->begin()));
    return QueryResult(req(),ret_lines,left.get_file());
}

QueryResult OrQuery::eval(const TextQuery& t)const {
    QueryResult left = lft.eval(t),right = rhs.eval(t);

    std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>(left.begin(),left.end());

    ret_lines->insert(right.begin(),right.end());
    return QueryResult(req(),ret_lines,left.get_file());
}

QueryResult NotQuery::eval(const TextQuery& t)const{
    QueryResult result = query.eval(t);
    std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
    std::set<line_no>::iterator beg = result.begin(),
        end = result.end();
    auto sz = result.get_file().size();
    for(size_t i=0;i<sz;++i)
    {
        if(beg == end || *beg != i)
            ret_lines->insert(i);
        else if(beg != end)
            ++beg;
    }

    return QueryResult(req(),ret_lines,result.get_file());
}
