#include "common.h"

int main(){
    int n = 5;
    auto f = [&n]() ->bool {
        return n>0? !--n:!n;
    };

    while(!f()){
        cout << n << " ";
    }
    cout << n << endl;
}
