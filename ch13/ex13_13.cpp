#include <iostream>
#include <vector>
using std::vector;

struct X{
    X(int i_=0){std::cout << "X()" << std::endl;i =new int(i_);}
    X(const X& rt){std::cout << "X(CONST X&)" << std::endl;i = new int;*i = *rt.i;}
    X& operator=(const X& rt){std::cout << "operator=(Const X&)" << std::endl;*i=*rt.i;return *this;}
    ~X(){std::cout << "~X()" << std::endl;delete i;}
    int *i;
};

void func(const X &x, X rx){
    vector<X> vec;
    vec.reserve(2);
    vec.push_back(x);
    vec.push_back(rx);
}

int main(){
    X x = 2;
    X *z = new X();
    X y(x);
    y = x;
    func(x,y);
    delete z;
    return 0;
}
