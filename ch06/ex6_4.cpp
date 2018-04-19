//
// Created by cxh on 18-1-1.
//
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int input(){
    int tmp;
    cout << "please input a interge:" <<endl;
    cin >> tmp;
    return tmp;
}

int fact(int num){
    int s = 1;
    while(num > 1){
        s *= num--;
    }
    return s;
}

int main(int argc,char** argv){
    int input_num;
    while(true){
        input_num = input();
        cout << "jiecheng :" << fact(input_num) << endl;
    }

    return 0;
}

