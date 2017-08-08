#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[]) {
  vector<int> vec;
  for (int i; cin >> i; vec.push_back(i))
    ;
  for (int j; j < vec.size(); j++) cout << vec[j] << endl;
  return 0;
}