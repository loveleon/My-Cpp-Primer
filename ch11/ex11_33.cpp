#include "common.h"

//word_transform
//buildMap
//transform
map<string,string> buildMap(ifstream &map_file);
const string & transform(string &word, const map<string,string> &m);

void word_transform(ifstream &map_file, ifstream &input){
        string line;
        map<string,string> m = buildMap(map_file);
        if(input){
            while(getline(input,line)){
                istringstream is(line);
                string word;
                bool is_firestword = true;
                while(is >> word){
                    if(is_firestword){
                        is_firestword = false;
                    }else{
                        cout << " "; //<< transform(word,m);
                    }
                    cout << transform(word,m);
                }
                cout << endl;
            }
        }
}

map<string,string> buildMap(ifstream &map_file){
    map<string,string> m;
    if(map_file){
        string word;
        string value;
        while(map_file >> word && getline(map_file,value)){
            if(value.size() > 1){
                m[word] = value.substr(1);
            }else{
                throw std::runtime_error("no rule for "+word);
            }

        }
    }
    return m;
}

const string & transform(string &word, const map<string,string> &m){
        auto it = m.find(word);
        if(it != m.end()){
            return it->second;
        }else{
            return word;
        }
}

int main(){
    ifstream map_file("../map_file.txt",map_file.in);
    ifstream input("../input.txt",input.in);
    word_transform(map_file,input);
    return 0;
}
