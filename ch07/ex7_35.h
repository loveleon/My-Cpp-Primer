#ifndef _EX7_35_H__
#define _EX7_35_H__
#include <string>
#include <iostream>
using std::string;

typedef string Type;
Type initVal();
class Exercise{
    public:
        typedef double Type;
        Type setVal(Type);
        Type initVal();
    private:
        int val;
};

Exercise::Type Exercise::setVal(Type param){
    val = param + initVal();
    return val;
}
#endif
