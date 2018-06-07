#include <memory>
#include <iostream>
#include <string>

using std::string;
using std::allocator;
using std::cout;
using std::endl;
using std::cin;

void allocator_string(int n){
    allocator<string> a;
    int i = 0;
    auto p = a.allocate(n);
    auto q = p;
    string str;
    while(cin >> str){
        if(i++ >= n){
            cout << "break at i=" << i << endl;
            break;
        }else{
            cout << i << endl;
        }
       a.construct(q++,str);
    }
    for(;q != p;){
        cout << *--q << endl;
        a.destroy(q);
    }
    a.deallocate(p,n);
}

int main(){
    int num = 5;
    allocator_string(num);

    return 0;
}

