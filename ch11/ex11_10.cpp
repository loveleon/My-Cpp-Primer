#include "common.h"

int main(){
    map<vector<int>::iterator,int> mv;
    map<list<int>::iterator,int> ml;

    vector<int> vec = {1,2,3,4,5};
    mv.insert(std::pair<vector<int>::iterator,int>(vec.begin(),0));

    /*   get error.
    list<int> lst{23,34};
    ml.insert(std::pair<list<int>::iterator,int>(lst.begin(),0));
   // */

    for(auto imv : mv){
        cout << *(imv.first) << " " << imv.second <<endl;
    }

    /*
    for(auto iml : ml){
        cout << *(iml.first) << " " << iml.second << endl;
    }
    // */

    return 0;
}
