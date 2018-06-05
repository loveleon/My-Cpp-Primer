#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using std::shared_ptr;
using std::vector;
using std::endl;
using std::cout;

vector<int> * create_vector(){
    return new vector<int>{};
}

shared_ptr<vector<int>> init_vector(vector<int> * it){
    shared_ptr<vector<int>> sit(it);
    int tmp;
    while(std::cin >> tmp){
        sit->push_back(tmp);
    }
    return sit;
}

void print(shared_ptr<vector<int>> sp){
    for_each(sp->begin(),sp->end(),[](const int &i){cout << i << " ";});
    cout << endl;
}

int main(){
    auto pVec = create_vector();
    auto sp = init_vector(pVec);
    print(sp);

    return 0;
}
