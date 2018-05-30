#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::bind;
using std::vector;

bool Size(const string &str,size_t sz);
void Count(vector<string> &vec,size_t sz){
    auto f = bind(Size,std::placeholders::_1,sz);
    auto cnt = std::count_if(vec.begin(),vec.end(),f);
    cout << "count smaller than " << sz << " has " << cnt << endl;
}

bool Size(const string &str,size_t sz){
    return str.size() <= sz ? true:false;
}

int main(){
    vector<string> vec = {"123","wers","hello world","sdfa","3werwee"};
    Count(vec,6);

    return 0;
}
