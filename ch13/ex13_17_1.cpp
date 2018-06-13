#include <iostream>
using std::cout;using std::endl;

class Numbered{
    public:
        Numbered(){num++;}
    public:
        static uint64_t num;
};

uint64_t Numbered::num = 0 ;


void f(Numbered s){
    cout << s.num << endl;
}


int main(){
    Numbered a,b=a,c=b;
    f(a);
    f(b);
    f(c);
    return 0;
}
