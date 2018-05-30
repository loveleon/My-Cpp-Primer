#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <functional>

using std::cout;
using std::vector;
using std::endl;
using std::string;
using std::cin;

bool check_size(const string &str,std::string::size_type sz){
    return str.size() < sz? true:false;
}

int main(){
    cout << "input a string:" << endl;
    string str;
    cin >> str;
    //vector<int> vec = {1,2,3,4,5,6,7,8,9};
    vector<string::size_type> vec = {1,2,3,4,5,6,7,8,9};
    auto f = bind(check_size,str,std::placeholders::_1);
    auto it = std::find_if(vec.begin(),vec.end(),f);
    if(it != vec.end())
        cout << "int number:" << *it << endl;
    else
        cout << "can't find integer." << endl;
    return 0;
}
