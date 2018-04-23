#include "comm/comm.h"
inline bool is_Shorter(const string& s1, const string& s2){
    return s1.size() < s2.size();
}

int main(){
    auto sm = false;
    sm = is_Shorter("32","322");
    cout << std::boolalpha << sm << endl;
}