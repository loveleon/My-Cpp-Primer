#include "comm/comm.h"
bool is_upper(const string& s){
    int i = 0;
    while(!s.empty()){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            return true;
        }
        i++;
    }
    return false;
}

void to_lower(string& s){
    int i = 0;
    int loop = s.size();
    for(i=0;i<loop;i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = tolower(s[i]);
            //s[i] = s[i] + 'Z' - 'A';
        }
    }
}

int main(void){
    string str = "abcddfgA";
    cout << "str " << str << " has upper character is " << std::boolalpha << is_upper(str) << endl;

    to_lower(str);
    cout << "str to lower " << str << endl;
    return 0;
}
