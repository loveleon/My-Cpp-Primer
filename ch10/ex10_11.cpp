#include "common.h"

void print(vector<string> &vec){
    cout << "print(vec): ";
    for(const auto item : vec){
        cout << item << " ";
    }
    cout << endl;
}
bool isShorter(const string &str1, const string &str2){
    if(str1.size() < str2.size()){
        return true;
    }else{
        return false;
    }
}

void elimDups(vector<string> &vec){
    std::sort(vec.begin(),vec.end());
    auto eniqu_it = std::unique(vec.begin(),vec.end());
    vec.erase(eniqu_it,vec.end());
}

int main(){
    vector<string> vec = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    elimDups(vec);
    std::stable_sort(vec.begin(),vec.end(),isShorter);
    print(vec);

    return 0;
}
