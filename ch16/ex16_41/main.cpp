#include <iostream>

template<typename T>
auto sum( T lft,  T rhs)->decltype(lft + rhs)
{
    return lft+rhs;
}

int main()
{
    auto s= sum(1236456789123456789, 1123456789123456789) ;
    std::cout << s << std::endl;
    return 0;
}

