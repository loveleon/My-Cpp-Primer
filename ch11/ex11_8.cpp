#include "common.h"

int main(){
    cout << "input many words:"<<endl;
    string word;
    vector<string> vec;
    set<string> setString;
    bool is_add = false;
    while(cin >> word){
        setString.insert(word);
        for(auto& w : vec){
            if(w == word){
                w = word+word;
                is_add = true;
                break;
            }
        }

        if(is_add){
            is_add = false;
            continue;
        }else{
            vec.push_back(word);
            is_add = false;
        }
        //is_add =false;
    }

    for(const auto& pw : vec){
        cout << pw << " ";
    }
    cout << endl;

    for(const auto& s : setString)
        cout << s << " ";
    cout << endl;

    return 0;
}
