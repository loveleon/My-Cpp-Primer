#include "ex13_18.h"

uint64_t Employee::no=0;
std::ostream& print(std::ostream &out, const Employee &e){
    out << e.name << " " << e.num;
    return out;
}
