#include <iostream>
#include <functional>
#include <numeric>

using std::function;
using std::accumulate;
struct int_div {
    float operator()(float x, float y){
        return float(x/y);
    }
};

//成员函数可被看做有额外参数的自由函数
struct X {
     int foo(int x){
         std::cout << "x :" << x <<std::endl;
        return x;
    }
};

function<int(X *,int)> Foo ;
std::function<float(float x, float y)> ff;

int main(){
    ff =  int_div();
    auto res = ff(7.5,2.5);
    std::cout << "result:" << res << std::endl;

    Foo = &X::foo;
    X x;
    Foo(&x,5);

    function<int(int)> F = std::bind(Foo,&x,std::placeholders::_1);
    int v = F(7);
//    std::cout << "v:" << v << std::endl;
    return 0;

}
