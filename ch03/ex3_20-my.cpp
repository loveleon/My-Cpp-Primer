#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<int> vec;
  for (int i; cin >> i; vec.push_back(i))
    ;
  // for (auto i : vec.size())
  for (auto j : vec) cout << j << " ";
  cout << endl;
  for (int m = 0, n = vec.size() - 1; m < vec.size() / 2; m++, n--)
    cout << (vec[m] + vec[n]) << " ";
  cout << endl;
  return 0;
}