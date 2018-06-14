#pragma once
#include <string>
#include <iostream>

class Employee{
    friend std::ostream& print(std::ostream &out, const Employee & e);
    public:
        Employee():name(std::string()),num(++no){}
        Employee(const std::string &nm):name(nm),num(++no){}
    private:
        std::string name;
        uint64_t num;
    public:
        static uint64_t no;
};

std::ostream& print(std::ostream &out, const Employee & e);
