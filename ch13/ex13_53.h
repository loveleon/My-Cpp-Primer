#pragma once
#include <string>
class HasPtr{
    public:
        friend void swap(HasPtr &, HasPtr &);
    public:
        HasPtr(const std::string &s = std::string());
        HasPtr(HasPtr &&p)noexcept;
        HasPtr &operator=(HasPtr rhs);
        HasPtr(const HasPtr &p);
        HasPtr &operator=(HasPtr &&p)noexcept;//ex13_54  二义性
        ~HasPtr();
    private:
        std::string *ps;
        int i;
};
