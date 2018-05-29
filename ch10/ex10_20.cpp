#include "common.h"

vector<string>::size_type Count(vector<string> &vec){
    auto cnt = std::count_if(vec.begin(),vec.end(),[](const string &str){
            return str.size() > 6   ;
            });
    return cnt;
}

int main(){
    vector<string> vec = {"hello world","im lilei","how old","haha"};
    cout << Count(vec) << endl;

    return 0;
}
