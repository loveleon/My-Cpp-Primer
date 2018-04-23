#include "comm/comm.h"

typedef vector<int>::iterator it;
void get_vector(it start, it end){
    if(start != end){
        cout << *start << " ";
        get_vector(++start, end);
        //get_vector(start++, end);
    }
    /*
    if(start == end){
        cout << *start << endl;
        return;
    }//*/
}

int main(){
    vector<int> v = {2,3,4,56,1,0,9};
    get_vector(v.begin(),v.end());

    return 0;
}
