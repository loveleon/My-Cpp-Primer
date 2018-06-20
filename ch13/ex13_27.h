#pragma once
#include <iostream>
class HasPtr;
std::ostream &print(std::ostream &out, HasPtr &has);
class HasPtr{
    friend std::ostream &print(std::ostream &out, HasPtr &has);
    public:
        HasPtr(const std::string &data=std::string()):data(new std::string(data)),use_count(new size_t(1)){}
        HasPtr(HasPtr &has);
        HasPtr &operator=(const HasPtr &has);
        ~HasPtr();
    private:
        std::string *data;
        std::size_t *use_count;
};
