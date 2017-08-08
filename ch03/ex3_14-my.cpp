#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;

int main() {
  vector<int> vec;
  int tmp;
  while (cin >> tmp) {
    vec.push_back(tmp);
    cout << tmp << std::endl;
  }
  return 0;
}