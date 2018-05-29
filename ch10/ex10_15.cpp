#include "common.h"

int sum(int &a){
    auto f = [&a](int b) ->int {
        return a+b;
    };
    int b = 100;
    return f(b);
}

int main(){
    int a = 1;
    cout << sum(a) << endl;
    return 0;
}
