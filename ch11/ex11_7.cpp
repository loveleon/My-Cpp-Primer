#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using std::map;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::istringstream;

int main(){
    using VEC = vector<string>;
    using VECIT = VEC::iterator; map<string,VEC>  mapNm;
    cout << "input family name and children name:"<<endl;
    string line;
    while(getline(cin,line)){
        string fname;
        istringstream all(line);
        all >> fname;
        string child;
        while(all >> child ){
            mapNm[fname].push_back(child);
        }
    }

    for(const auto& fn : mapNm){
        cout << fn.first << " ";
        for(const auto cd : fn.second){
            cout << cd << " ";
        }
        cout << endl;
    }

    return 0;
}
