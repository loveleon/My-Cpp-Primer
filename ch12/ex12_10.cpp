#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cout;
using std::endl;

int process(shared_ptr<int> ptr){
    cout << *ptr << endl;
    return *ptr;
}

int main(){
    shared_ptr<int> p ( new int(100));
    cout << process(p) << endl;

    auto sz = p.use_count();
    cout << sz << endl;

    return 0;
}
