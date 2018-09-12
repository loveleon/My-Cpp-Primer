#include <iostream>
using std::cout;
using std::endl;

template<typename T> void f(T t)
{
    std::cout << "f(T) ";
    std::cout << t << std::endl;
}

template<typename T> void f(const T* t)
{
    std::cout << "f(const T*) ";
    std::cout << *t << std::endl;
}

template<typename T> void g(T t)
{
    std::cout << "template <typename T> void g(T) ";
    std::cout << t << std::endl;
}

template<typename T> void g(T* t)
{
    std::cout << "template <typename T> void g(T*) ";
    std::cout << *t << std::endl;
}

int main(){
    int i = 42, *p = &i;
    const int ci = 0,*p2 = &ci;
    g(42);//T = int g(T)
    g(p);//T =int g(T*)
    g(ci);//T =const int g(T)
    g(p2);//T = const int g(T*)
    f(42);//T = int f(T)
    f(p);//T = int f(const T*)[error] --> T = int* f(T)
    f(ci);//T = int f(T)
    f(p2);//T = int f(const T*)
    return 0;
}
