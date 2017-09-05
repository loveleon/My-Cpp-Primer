#include <iostream>
#include <vector>
// using namespace std;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  // vector<int> vec;
  cout << "vecotr at 0:" << vec.at(0) << endl;
  cout << "vec[0] :" << vec[0] << endl;
  cout << "vec.front:" << vec.front() << endl;
  cout << "vec.begin():" << *(vec.begin()) << endl;
  return 0;
}