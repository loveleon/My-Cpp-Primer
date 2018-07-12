#include "ex13_53.h"
#include <iostream>

void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i, rhs.i);
}

HasPtr::HasPtr(const std::string &s):ps(new std::string(s)),i(0){
    std::cout << "default constructor." << std::endl;
}

HasPtr::HasPtr(const HasPtr &s):ps(new std::string(*s.ps)),i(s.i){
    std::cout << "copy constructor." << std::endl;
}

HasPtr::HasPtr(HasPtr &&s)noexcept :ps(s.ps),i(s.i){
    s.ps = nullptr;
    std::cout << " move constructor." << std::endl;
}

HasPtr& HasPtr::operator=(HasPtr rhs){
    swap(*this,rhs);
    std::cout << "assign-operator"<< std::endl;
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhs)noexcept{
    if(this != &rhs){
    ps = rhs.ps;
    i = rhs.i;
    rhs.ps = nullptr;
    std::cout << "move oprator." << std::endl;
    }
    return *this;

}

HasPtr::~HasPtr(){
    std::cout << "~HasPtr" << std::endl;
    delete ps;
}
