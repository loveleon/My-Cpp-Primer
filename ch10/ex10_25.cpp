#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using std::string;
using std::cout;
using std::endl;
using std::vector;

void elimDups(vector<string> &vec){
    std::sort(vec.begin(),vec.end());
    auto unique_it =  std::unique(vec.begin(),vec.end());
    vec.erase(unique_it,vec.end());
}

bool check_size(const string &str,std::size_t sz){
    return str.size() >= sz ;
}

int main(){
    vector<string> vec = {"123456","hello","world","lilei","how-old","name"};
    std::size_t sz = 5;
    elimDups(vec);
    auto it = std::partition(vec.begin(),vec.end(),bind(check_size,std::placeholders::_1,sz));
    cout << "bigger than " << sz << " is :" <<endl;
    for_each(vec.begin(),it,[](const string &str){cout << str << " ";});
    cout << endl;

    return 0;
}

