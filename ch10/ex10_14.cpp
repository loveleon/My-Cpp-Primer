#include "common.h"

int main(){
    auto f = [](const int &a, const int &b) -> int {
        return a + b;
    };
    cout << "sum :" << f(5,10) << endl;

    return 0;
}
