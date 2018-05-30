#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using std::vector;
using std::list;
using std::set;
using std::cout;
using std::endl;

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    vector<int> fvec,bvec,ivec;
    list<int> flst,blst,ilst;
    set<int> s;

    //set -->inserter  no support push_back push_front
    std::copy(vec.cbegin(),vec.cend(),inserter(s,s.begin()));
    cout << "set :" << endl;
    for_each(s.cbegin(),s.cend(),[](const int &i){cout << i << " ";});
    cout << endl;

    //list inserter back_inserter front_inserter
    std::copy(vec.cbegin(),vec.cend(),back_inserter(blst));
    std::copy(vec.cbegin(),vec.cend(),front_inserter(flst));
    std::copy(vec.cbegin(),vec.cend(),inserter(ilst,ilst.begin()));

    cout << "front insert list :";
    for_each(flst.cbegin(),flst.cend(),[](const int &i){cout << i << " ";});
    cout << endl;

    cout << "back insert list:";
    for_each(blst.cbegin(),blst.cend(),[](const int &i){cout << i << " ";});
    cout << endl;

    cout << "insert list:";
    for_each(ilst.cbegin(),ilst.cend(),[](const int &i){cout << i << " ";});
    cout << endl;
    //vector push_back insert
    std::copy(vec.cbegin(),vec.cend(),back_inserter(bvec));
    std::copy(vec.cbegin(),vec.cend(),inserter(ivec,ivec.begin()));

    cout << "back insert vector :" << endl;
    for_each(bvec.cbegin(),bvec.cend(),[](const int &i){cout << i << " ";});
    cout << endl;

    cout << "insert vector :" << endl;
    for_each(ivec.cbegin(),ivec.cend(),[](const int &i){cout << i << " ";});
    cout << endl;
    return 0;
}
