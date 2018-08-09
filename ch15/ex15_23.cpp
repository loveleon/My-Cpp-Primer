#include <iostream>
class Base{
    public:
        virtual int fcn(){std::cout << "Base::fcn()" << std::endl;return 0;};
};

class D1 :public Base {
    public:
    int fcn(int n){std::cout << "D1::fcn(int)" <<std::endl;return n;}//
    virtual int fcn() override {std::cout << "D1::fcn()" << std::endl;return 0;}//
    virtual void f2(){std::cout << "D1::f2()" << std::endl;}
};

class D2 : public D1{
    public:
        virtual void f2() override{std::cout << "D2::f2()" << std::endl;}//overload D1::f2()
        int fcn() override{std::cout << "D2::fcn()" << std::endl;return 0;}//overload base:fcn()
};

int main()
{
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj;
    Base *bp2 = &d1obj;
    Base *bp3 = &d2obj;

    bp1->fcn();//base::fcn
    bp2->fcn();//D1::fcn()
    bp3->fcn();//D2::fcn()

    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
//    bp2->f2();//error
    d1p->f2();//D1::f2()
    d2p->f2();//D2::f2()

    d1p->fcn(1);
    return 0;
}
