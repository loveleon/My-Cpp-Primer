#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int a[10];
  for (int i; i < 10; i++) a[i] = i;
  std::vector<int> vec;
  for (auto v : a) vec.push_back(v);
  cout << endl;
  for (auto v2 : vec) cout << v2 << " ";
  return 0;
}