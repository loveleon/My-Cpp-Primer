//ex16.37
//yes ,just offer an explicit template argument.
//int a,double b;
//max<double>(a,b)
//
//ex16.38
//make_shared has no posibility to determine how big size it should allocate,which is
//the reason.
//
//dependint the specified ,make_shared allocat proper size of memory space and return a proper
//type of shared_ptr pointing to it;
//
//ex16.39
//
#include <iostream>
#include <string>

template<typename T>
int compare(const T& lft,const T& rhs)
{
    if(lft < rhs)
        return -1;
    else if(lft > rhs)
        return 1;
    else
        return 0;
}

int main()
{
    std::cout << compare<std::string>("aaa","aaa") << std::endl;
    std::cout << compare<std::string>("aaa","aab") << std::endl;
    std::cout << compare<std::string>("aac","aab") << std::endl;
    return 0;
}
