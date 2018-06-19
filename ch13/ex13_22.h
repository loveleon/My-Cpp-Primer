#pragma once
#include <iostream>
#include <string>

class HasPtr;
std::ostream & print(std::ostream &out, HasPtr &has);
class HasPtr{
    public:
        friend std::ostream & print(std::ostream &out, HasPtr &has);
    public:
    HasPtr(const HasPtr &lf);
    HasPtr(const std::string &str=std::string(),int sz=0):ps(new std::string(str)),i(sz){}
    HasPtr & operator=(HasPtr &rt);
    ~HasPtr();
    private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &lf){
    ps = new std::string(*lf.ps);
    i = lf.i;
}

HasPtr::~HasPtr(){
    delete ps;
}

HasPtr & HasPtr::operator=(HasPtr &rt){
    auto new_ps = new std::string(*rt.ps);
    delete ps;
    ps = new_ps;
    i = rt.i;
    return *this;
}

std::ostream & print(std::ostream &out, HasPtr &has){
    out << has.ps << " " << *has.ps << " " << has.i;
    return out;
}
