#include <memory>
#include <vector>
#include <iostream>
using std::shared_ptr;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

shared_ptr<vector<int>> NewVector(){
    auto v = std::make_shared<vector<int>>();
    return v;
}

shared_ptr<vector<int>> InitVector(shared_ptr<vector<int>> v){
    int i;
   for(i=0;cin >> i;v->push_back(i));
   return v;
}

void PrintVector(shared_ptr<vector<int>> v){
    for(auto i : *v)
        std::cout << i << " ";
    cout <<endl;
}

int main(){
    auto v = NewVector();
    auto V = InitVector(v);
    PrintVector(V);
    return 0;
}
