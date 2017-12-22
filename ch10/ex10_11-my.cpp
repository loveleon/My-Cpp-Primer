#include    <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::vector;

void elimDups(vector<std::string> &v)
{
    std::cout << "input vector<string> :"<<std::endl;
    for (auto i : v)
        std::cout << i << " ";
    std::cout <<std::endl;

    //1.sort
    sort(v.begin(),v.end());
    //2.去重
    auto it = std::unique(v.begin(),v.end());
    v.erase(it,v.end());
    for(auto i: v)
        std::cout << i << std::endl;
    std::cout << std::endl;
}

bool isShorter(std::string a, std::string b)
{
//    return std::size(a) < std::size(b);
    return a.length() < b.length();
}


int main(){
    std::vector<std::string> v = {"123","345","123","2334","234","2334","2234"};
    elimDups(v);
    std::cout << "after elimDups:"<< std::endl;
    for(auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    std::stable_sort(v.begin(),v.end(),isShorter);
    std::cout << "after stable_sort:" << std::endl;
    for(auto i : v)
        std::cout <<i << " ";
    std::cout << std::endl;

    return 0;
}
