#include <iostream>
#include <utility>
void g(int&& i,int& j)
{
    std::cout << i << " " << j << std::endl;
}

void gg(int &i,int j){
    std::cout << i << " " << j << std::endl;
}

void ggg(int &i,int&& j){
    std::cout << i << " " << j << std::endl;
}

template<typename F,typename T1,typename T2>
void Func(F f,T1&& t1, T2&& t2)
{
    //std::forward() usually uses to pass parameter to rvalue reference template function to keep parameter real type.
    f(std::forward<T2>(t2),std::forward<T1>(t1));
}

int main()
{
    int i = 10;
    Func(g,i,42);
    Func(gg,42,i);
    Func(ggg,42,i);
    return 0;
}
