#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  for (int i; cin >> i; v.push_back(i))
    ;
  for (auto it = v.begin(); it != v.end(); it++) (*it) = (*it) * 2;
  for (auto j : v) cout << j << " ";
  cout << endl;
  return 0;
}