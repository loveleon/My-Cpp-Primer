#include "comm/comm.h"
void f(){
    cout << "f()" << endl;
}

void f(int a){
    cout << "f(int a)" << " ";
    cout << a <<endl;
}

void f(int a, int b){
    cout << "f(int a,b)" << " ";
    cout << a << " " << b << endl;
}

void f(double a, double b= 3.14){
    cout << " f(double a,b)" << " ";
    cout << a << " " << b <<endl;
}

int main(){
   // f(2.56,42); //ambiguous
    f(42);   // number2
    f(42,0); //number 3
    f(2.56,3.33); //number 4

    return 0;

}