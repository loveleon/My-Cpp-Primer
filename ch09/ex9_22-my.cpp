#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int>::iterator ittmp;
  vector<int>::iterator it = vec.begin(), mid = vec.begin() + vec.size() / 2;
  while (it != mid) {
    ittmp = it;
    if (*it == 2) vec.insert(ittmp, 2 * 2);
    ++it;
  }
  for (auto i : vec) cout << i << " ";
  cout << endl;
  return 0;
}