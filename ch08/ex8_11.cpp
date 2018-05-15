#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;using std::endl;using std::cerr;
using std::fstream;using std::stringstream;
using std::string;
using std::vector;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main(){
    string line,word;
    vector<PersonInfo> people;
    std::istringstream record;
    while(getline(std::cin,line)){
    //    std::istringstream record(line);
        PersonInfo  info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for(auto& info : people){
        cout << info.name << " ";
        for(auto ph : info.phones){
            cout << ph << " ";
        }
        cout << endl;
        }
    return 0;
}
