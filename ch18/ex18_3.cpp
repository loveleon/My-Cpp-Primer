//
// Created by cxh on 18-10-22.
//
#include <exception>
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
using std::ifstream;
using std::vector;

struct intArray{
  intArray():data(nullptr){}
  intArray(int _size){
    data = new int[_size];
    std::cout << __func__ << " called." << std::endl;
  }
  ~intArray(){
    delete []data;
  }
  int *data;
};

void exercise(int *b, int *e){
  vector<int> vec(b,e);
  intArray p(10);
  std::shared_ptr<int> sp(new int[10],[](int *p){delete []p;std::cout << "shared_ptr deconstructor called ." << std::endl;});
  ifstream in("../ex18_1.cpp");
}

int main(){
  vector<int> vec{1,2,3,4,5};
  exercise(&vec[0], &vec[vec.size()-1]);
  return 0;
}

