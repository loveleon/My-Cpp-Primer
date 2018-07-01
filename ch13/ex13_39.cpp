#include "ex13_39.h"
StrVec::StrVec(const StrVec &v){
   auto data = alloc_n_copy(v.begin(),v.end());
   element = data.first;
   first_free = cap = data.second;
}

StrVec & StrVec::operator=(const StrVec &v){
    auto data = alloc_n_copy(v.element,v.first_free);
    free();
    element = data.first;
    first_free = cap = data.second;
    return *this;
}

std::pair<std::string *,std::string *> StrVec::alloc_n_copy(const std::string *beg,const std::string *end){
   auto data = alloc.allocate(end - beg);
   return {data,std::uninitialized_copy(beg,end,data)};
}


void StrVec::chk_n_alloc(){
    if(size() == capacity()){
        reallocate();
    }
}

void StrVec::reallocate(){
    //
    auto new_cap = size()?2*size():1;
    alloc_n_move(new_cap);
}

void StrVec::alloc_n_move(std::size_t newcap){
    auto data = alloc.allocate(cap-element);
    auto dest = data;
    auto elem = element;
    for(size_t i = 0; i != size();++i){
       alloc.construct(dest++,std::move(*elem++));
    }
    free();
    element = data;
    first_free = dest;
    cap = element + newcap;
}

void StrVec::free(){
    if(element){
        for(auto p = first_free; p != element; )
            alloc.destroy(--p);
        alloc.deallocate(element,cap-element);
    }
}

StrVec::~StrVec(){
    free();
}

void StrVec::push_back(const std::string &s){
    chk_n_alloc();
    alloc.construct(first_free++,s);
}

void StrVec::reserve(std::size_t newcap){
    if(newcap < capacity())
        return ;
    alloc_n_move(newcap);
}

void StrVec::resize(std::size_t newsize) {
}
