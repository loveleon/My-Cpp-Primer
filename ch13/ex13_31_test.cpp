#include "ex13_31.h"
#include <vector>
#include <algorithm>
using std::vector;

int main(){
    vector<HasPtr> vec;
    HasPtr has1("test",4);
    HasPtr has2("aaa",3);
    HasPtr has3("bbb",3);
    HasPtr has4("zzz",3);
    HasPtr has5("abc",3);
    vec.push_back(has1);
    vec.push_back(has2);
    vec.push_back(has3);
    vec.push_back(has4);
    vec.push_back(has5);
    //*
 //   std::sort(vec.begin(),vec.end(),[](const HasPtr &lf,const HasPtr &rt){return *lf.data < *rt.data;});//okay
    std::sort(vec.begin(),vec.end());//,[](const HasPtr &lf,const HasPtr &rt){return *lf.data < *rt.data;});
    //*/
    for(auto &has : vec){
        print(std::cout,has)<<std::endl;
    }
    return 0;
}
