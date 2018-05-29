#include "ex10_16.h"

void elimDups(vector<string> &vec);
void biggies(vector<string> &vec,vector<string>::size_type sz){
    elimDups(vec);
    vector<string>::iterator it = std::partition(vec.begin(),vec.end(),[sz](const string &str){
            return str.size() < sz;
            });
    int count = vec.end() - it;
    cout << "bigger than " << sz << " has " << count << endl;
    for(auto start = it;start != vec.end(); ++start){
        cout << *start << " ";
    }
    cout << endl;
}

int main(){
    vector<string> vec = {"12345","abcdf","wdc","zzzzz","yyuwew","hello"};
    biggies(vec,4);

    return 0;
}
