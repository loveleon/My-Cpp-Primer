#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;


vector<int> *  create_vector(){
    auto vec = new vector<int>{};

    return vec;
}

void init_vector(std::istream &in,vector<int> *vec){
    int tmp;
    cout << "input :" << endl;
    while(in >> tmp){
        vec->push_back(tmp);
    }
}

void print(vector<int> *vec){
    std::for_each((*vec).cbegin(),(*vec).cend(),[](const int &i){cout << i << " ";});
    cout  << endl;
}

void destructor(vector<int> *vec){
    delete vec;
    vec = nullptr;
}

int main(){
    auto vec = create_vector();
    init_vector(std::cin,vec);
    print(vec);

    destructor(vec);
    return 0;

}
