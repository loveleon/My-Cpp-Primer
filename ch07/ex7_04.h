#ifndef _EX7_04_H__
#define _EX7_04_H__
#include "comm.h"

class Person{
    private:
        string name;
        string addr;
    public:
       string const& get_name()const{
            return name;
        }
        const string& get_addr()const{
            return addr;
        }
    friend istream& read(istream& os, Person& p);
    friend ostream& print(ostream& os, const Person& p);

};

istream& read(istream& os, Person& p){
    os >> p.name >> p.addr;
    return os;
}

ostream& print(ostream& os, const Person& p){
    os << p.name << " " << p.addr;
    return os;
}

#endif
