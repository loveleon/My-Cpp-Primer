//
// Created by cxh on 18-1-1.
//
#include "comm.h"

int testLocalStatic(int base_num){
    int local = 1;
    static int local_static = 1;
    cout << base_num << "+" << local_static << " + " << local << "=" << base_num + local_static + local << endl;
    local_static ++;
    local++;
    cout << local_static << " " << local << endl;
    return  0;
}

int main(){
    int loop;
    cout << "input loop number:" <<endl;
    cin >> loop;
    while(loop > 0){
        loop--;
        testLocalStatic(loop--);
    }
}
