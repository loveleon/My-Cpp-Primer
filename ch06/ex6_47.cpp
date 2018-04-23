#include "comm/comm.h"

typedef vector<int>::iterator It;
void print(It start, It end){
        if(start != end){
            cout << *start << " ";
#ifndef NDEBUG
            cout << "NOT DEFINE NDEBUG ..." << endl;
#else
            cout <<  "DEFINE NDEBUG..." << endl;
#endif
            print(++start,end);
        }
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    print(v.begin(),v.end());

    return 0;
}