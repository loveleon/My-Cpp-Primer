#include "comm/comm.h"

int factorial(int num){
    if(num != 0){
        cout << num << " * ";
    //if(num > 1){
        return factorial(num-1)*num;
    }else{
        cout << num << " = ";
        return 1;
    }
//    return 1;
}

int main(int argc,char** argv){
    int num = 5;
    if(argc == 2){
        num = atoi(argv[1]);
    }
    int total = factorial(num);
    cout << total << endl;
    return 0;
}
