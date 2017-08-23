#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};
  vector<int> vec = {begin(arr), end(arr)};
  for (auto i = vec.begin(); i != vec.end(); i++) cout << *i << " ";
  cout << endl;
  return 0;
}