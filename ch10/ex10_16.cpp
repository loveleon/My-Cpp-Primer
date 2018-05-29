#include "ex10_16.h"

void elimDups(vector<string> &vec);
void biggies(vector<string> &vec,vector<string>::size_type sz){
    elimDups(vec);
    std::stable_sort(vec.begin(),vec.end(),[](const string &str1, const string &str2) -> bool{
            return str1.size() < str2.size();
            });
    vector<string>::iterator it =  std::find_if(vec.begin(),vec.end(),[sz](const string &str) ->bool {
                return str.size() > sz;
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
