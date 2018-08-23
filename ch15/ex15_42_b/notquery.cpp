#include "notquery.h"
#include <set>

QueryResult NotQuery::eval(const TextQuery& t)const{
    QueryResult res = query.eval(t);

    std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();

    std::set<TextQuery::line_no>::iterator beg = res.begin(),end = res.end();
    StrBlob::size_type sz = res.get_file().size();

    for(size_t n=0;n <sz;++n)
    {
        if(beg == end || *beg == n)
            ret_lines->insert(n);
        else if(beg != end)
            ++beg;
    }

    return QueryResult(req(),ret_lines,res.get_file());
}
