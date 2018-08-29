#include <iostream>
#include <string>
using std::string;

template<typename T,unsigned size>
constexpr unsigned getSize(T (&)[size])
{
    return size;
}

int main()
{
    string str[] = {"a","b","c","d","e"};
    std::cout << getSize(str) << std::endl;

    char c[] = {"a"};
    std::cout << getSize(c) << std::endl;
    return 0;
}

//ex16_8 all of standard c++ library have defined operator != and == ,not all of them defined < operator.
