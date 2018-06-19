#pragma once
#include <string>
#include <iostream>
class HasPtr{
    public:
        HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
        HasPtr(const HasPtr &lf);
        HasPtr & operator=(const HasPtr &lf);
        ~HasPtr();
        void print(){std::cout << *ps << " " << i << std::endl;}
    private:
        std::string *ps;
        int i;
};

HasPtr::~HasPtr(){
    delete ps;
}

HasPtr::HasPtr(const HasPtr &has){
    auto new_ps = new std::string(*has.ps);
    delete ps;
    ps = new_ps;
    i = has.i;
}

HasPtr& HasPtr::operator=(const HasPtr &lf){
    ps = new std::string(*lf.ps);
    i = lf.i;
    return *this;
}



