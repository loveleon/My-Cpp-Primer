#include <iostream>
#include <string>
#include <vector>

template<typename T>
void print(T const& t)
{
    for(auto it:t )
        std::cout << it << "\t";
}

int main()
{
    std::vector<int> ivec = {1,2,3,4,5,6};
    std::string s[] = {"123","234","345","456"};
    char c[] = {'a','b','c','d'};
    print(ivec);
    std::cout << std::endl;
    print(s);
    std::cout << std::endl;
    print(c);
    std::cout << std::endl;
    return 0;
}
