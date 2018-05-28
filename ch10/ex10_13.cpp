#include "common.h"


bool size(const string &str){
    if(str.size() >= 5)
        return true;
    return false;
}

int main(){
    vector<string> vec = {"hello","world","i","am","lilei","how","are","you","what's","yours","names"};
    auto it = std::partition(vec.begin(),vec.end(),size);
    for(auto item : vec){
        cout << item << " ";
    }
    cout << endl;
    auto ii = vec.begin();
    for(/*auto ii = vec.begin()*/;ii != it;ii++){
        cout << *ii << " ";
    }
    cout << endl;
    return 0;
}
