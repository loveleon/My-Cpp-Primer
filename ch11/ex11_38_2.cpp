#include "common.h"
#include <unordered_map>
using std::unordered_map;

unordered_map<string,string> buildMap(ifstream &map_file){
    unordered_map<string,string> m;
    string key;
    string value;
    while(map_file >> key && getline(map_file,value)){
        if(value.size() > 1){
            m[key] = value.substr(1);
        }else{
            throw std::runtime_error("no rule for "+key);
        }
    }
    return m;
}

const string & transform(string& word,unordered_map<string,string> &m){
    auto it = m.find(word);
    if(it != m.end()){
        return it->second;
    }else{
        return word;
    }
}
void word_transform(ifstream &map_file,ifstream &input){
    unordered_map<string,string> m = buildMap(map_file);
    string word;
    string line;
    bool is_firstword;
    if(input){
        while(getline(input,line)){
            istringstream is(line);
            is_firstword=true;
            while(is >> word){
                if(is_firstword){
                    is_firstword = false;
                }else{
                    cout << " ";
                }
                cout << transform(word,m);
            }
            cout << endl;
        }
    }
}
int main(){
    ifstream map_file("../map_file.txt",map_file.in);
    ifstream input("../input.txt",input.in);
    word_transform(map_file,input);

    return 0;
}
