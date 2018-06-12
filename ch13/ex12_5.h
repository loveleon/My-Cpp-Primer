#pragma once
#include <string>
#include <iostream>
class HasPtr{
    public:
        HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
        HasPtr(const HasPtr &lf);
        void print(){std::cout << *ps << " " << i << std::endl;}
    private:
        std::string *ps;
        int i;
};

HasPtr::HasPtr(const HasPtr &has){
    ps = new std::string(*has.ps);
    i = has.i;
}



