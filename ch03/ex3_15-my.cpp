#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::cout;
using std::cin;
using std::string;

int main() {
  vector<std::string> vec;
  std::string tmp;
  while (cin >> tmp) {
    vec.push_back(tmp);
    cout << tmp << std::endl;
  }
  return 0;
}