#pragma once
#include <iostream>
#include <string>
using std::string;
class HasPtr;
void swap(HasPtr &lf,HasPtr &rt);
std::ostream &print(std::ostream &out, HasPtr &has);
class HasPtr{
    friend  void swap(HasPtr &lf, HasPtr &rt);
    friend std::ostream &print(std::ostream &out, HasPtr &has);
    friend bool operator<(HasPtr &lf,HasPtr &rt);
    public:
        HasPtr(const std::string &str=std::string(),int sz=0):data(new std::string(str)),i(sz){}
        HasPtr(const HasPtr &rt):data(new std::string(*rt.data)),i(rt.i){}
        HasPtr &operator=(HasPtr &rt);
        ~HasPtr(){delete data;}
    private:
        std::string *data;
        int i;
};
