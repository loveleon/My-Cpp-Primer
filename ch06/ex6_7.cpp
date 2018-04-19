//
// Created by cxh on 18-1-1.
//
#include "comm/comm.h"
//#include "comm.h"
//static int flag = 0;

int different_return_value(){
    static int flag = 0;
    int tmp = flag;
    flag++;
    return tmp;
}

int main(){
    cout << "call function times:"<<endl;
    int times;
    cin >> times;
    int ret;
    while(times--){
        ret = different_return_value();
        cout << ret << "..." <<endl;
    }
}
