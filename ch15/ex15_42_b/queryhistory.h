#pragma once
#include "query.h"
#include <vector>
using std::vector;

class Query_History{
    public:
        Query& operator[](size_t n){
            return *(query_vec[n]);
        }
        size_t add_query(const Query&);
    private:
        vector<std::shared_ptr<Query>> query_vec;

};
