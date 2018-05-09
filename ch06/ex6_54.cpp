#include "comm/comm.h"

typedef int Func(int,int);
vector<Func *> v;

int Add(int a, int b){
    return a+b;
}

int Sub(int a, int b){
    return a- b;
}

int Mutil(int a, int b){
    return a*b;
}

int Divi(int a, int b){
    return a/b;
}

int main(){
    v.push_back(Add);
    v.push_back(Sub);
    v.push_back(Mutil);
    v.push_back(Divi);
    int a = 10 ,b=2;
    for( auto func : v ){
      auto tmp =  func(a,b);
      cout << tmp << endl;
    }
    return 0;
}
