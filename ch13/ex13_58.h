#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>

class Foo{
    public:
        friend std::ostream &print(std::ostream &out, const Foo &);
    public:
        Foo() =default;
        Foo(std::initializer_list<int> list);
        Foo sorted() &&;
        Foo sorted() const &;
    private:
        std::vector<int> data;
};

std::ostream &print(std::ostream &out, const Foo &);

