#ifndef _EX7_15_H__
#define _EX7_15_H__
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::endl;
using std::string;

struct Person{
    std::string name;
    std::string addr;
    Person() = default;
    Person(std::istream& in);
    Person(std::string nm, std::string ad):name(nm),addr(ad){}
};

Person::Person(std::istream& in){
    in >> name >> addr;
}

std::istream& read(std::istream& in, Person& p){
    in >> p.name >>p.addr;
    return in;
}

std::ostream& print(std::ostream& out,Person& p){
    out << p.name << " " << p.addr ;
    return out;
}
#endif
