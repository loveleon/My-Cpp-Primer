#include "common.h"

void print(vector<string> &vec){
    for(const auto &i : vec){
        cout << i << " ";
    }
    cout << endl;
}

void elimDups(vector<string> &vec){
    cout << "input:" << endl;
    print(vec);
    std::sort(vec.begin(),vec.end());
    cout << "after sort:" << endl;
    print(vec);
    auto eniqu_it = std::unique(vec.begin(),vec.end());
    cout << "after unique:" << endl;
    print(vec);
//    vec.erase(eniqu_it);
    vec.erase(eniqu_it,vec.end());
    cout << "after erase:" <<endl;
    print(vec);
}

int main(){
    vector<string> vec = {"the","quick","red","fox","jumps","over","the","red","slow","turtle"};
    //vector<string> vec = {"fox","jumps","over","quick","red","slow","the","turtle"};
    elimDups(vec);
    return 0;
}
