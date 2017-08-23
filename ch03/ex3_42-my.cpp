#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  // init an array with a vector
  std::vector<int> v;
  for (int i; cin >> i; v.push_back(i)) {
    ;
  }

  // constexpr size_t array_size = v.size();
  // int arr[array_size] = {0};//error
  int arr[10] = {0};
  int i = 0;
  for (auto j : v) {
    arr[i++] = j;
    std::cout << j << " ";
  }
  cout << endl;
  for (auto it = begin(arr); it != end(arr); ++it) cout << *it << " ";
  // for (auto it : arr) cout << it << " ";
  cout << endl;
  return 0;
}