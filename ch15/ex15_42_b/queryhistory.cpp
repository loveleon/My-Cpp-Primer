#include "queryhistory.h"

size_t Query_History::add_query(const Query& q){
    std::shared_ptr<Query> sp = std::make_shared<Query>(q);
    query_vec.push_back(sp);
    return query_vec.size() - 1;
}
