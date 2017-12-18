#include <vector>
#include <memory>
#include <iostream>
using std::vector;
using std::shared_ptr;
using std::cin;

vector<int>* NewVector(){
//vector<int>* NewVector(vector<int>::size_type s){
    //auto v = new vector<int>(s,0);
    auto v = new vector<int>;
    return v;
}

void InitVector(vector<int> * v){
    int i;
    for(i=0;cin >> i; (*v).push_back(i));
}

void PrintVector(vector<int>* v){
    for(auto i : *v)
        std::cout << i << " ";
    std::cout<<std::endl;
    delete v;
}

int main(){
    auto v = NewVector();
    InitVector(v);
    PrintVector(v);
    return 0;
}

