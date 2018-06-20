#include "ex13_27.h"

HasPtr::HasPtr(HasPtr &has){
    data = has.data;
    use_count = has.use_count;
    ++*use_count;
    std::cout <<__func__<<  " use_count:" << *use_count << std::endl;
}

HasPtr::~HasPtr(){
    if(*--use_count == 0)
    {
        std::cout <<__func__<<  " use_count:" << *use_count << std::endl;
        delete data;
        delete use_count;
    }
}

HasPtr & HasPtr::operator=(const HasPtr &has){
    ++*has.use_count;
    auto pdata = has.data;
    if((--*use_count) == 0){
        std::cout <<__func__<<" " << __LINE__ <<  " use_count:" << *use_count << std::endl;
        delete data;
        delete use_count;
    }
    data = pdata;
    use_count = has.use_count;
    std::cout <<__func__<< " "<<__LINE__ <<  " use_count:" << *use_count << std::endl;
    return *this;
}

std::ostream &print(std::ostream &out, HasPtr &has){
    out << *has.data;
    return out;
}
