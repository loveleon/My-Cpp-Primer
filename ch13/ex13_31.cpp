#include "ex13_31.h"
void swap(HasPtr &lf, HasPtr &rt){
    using std::swap;
    swap(lf.data,rt.data);
    swap(lf.i,rt.i);
    std::cout << __func__ << " "<< __LINE__ << " swap called" <<std::endl;
}

std::ostream &print(std::ostream &out, HasPtr &has){
    out << *has.data << " " << has.i;
    return  out;
}
//*
//HasPtr &HasPtr::operator=(HasPtr &rt){//this is error.rt cannot be a reference type
HasPtr &HasPtr::operator=(HasPtr rt){
    using std::swap;
    swap(*this,rt);
    return *this;
}
//*/
/*
HasPtr &HasPtr::operator=(HasPtr rt){
    auto data_ = new std::string(*rt.data);
    delete data;
    data = data_;
    i = rt.i;
    return *this;
}
*/

bool operator<(const HasPtr &lf, const HasPtr &rt){
    return *lf.data < *rt.data;
}
