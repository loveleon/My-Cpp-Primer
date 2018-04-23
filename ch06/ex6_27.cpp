#include "comm/comm.h"
#include <initializer_list>
using std::initializer_list;
int sum(initializer_list<int> list){
    int sum = 0;
    for(auto i : list)
        sum += i;

    return sum;
}

int main(){
    auto list = {1,2,3,4,5,6};
    cout << "sum :" << sum(list) <<endl;
    return 0;
}
