#ifndef _EX7_43_H__
#define _EX7_43_H__
#include <iostream>
class NoDefault{
    public:
        NoDefault(int i):num(i){}
        void print(){std::cout << "num:" << num << std::endl;}
    private:
            int num;
};

class C{
    public:
        C():c(0),no(0){}
        void print(){std::cout << "c:" << c << " " <<  std::endl;no.print();}

    public:
        int c;
        NoDefault no;
};
#endif
