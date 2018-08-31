#include <iostream>
#include <vector>
#include <list>
#include <string>
using std::vector;
using std::list;
using std::string;

template<typename T> void print(const T& t)
{
    typedef typename T::size_type size_type;
    auto it = t.begin();
    for( size_type i=0; i< t.size();++i,++it)
    {
        std::cout << *it << "\t";
    }
    std::cout << std::endl;
}

template<typename T> void print_two(const T& t)
{
    for(auto it = t.begin();it != t.end();++it)
        std::cout << *it << "\t";
    std::cout << std::endl;
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7};
    list<string> lst = {"cxh","hello","world","time"};

    //ex16_19
    //print(vec);
    //print(lst);

    //ex16_20
    print_two(vec);
    print_two(lst);

    return 0;
}
