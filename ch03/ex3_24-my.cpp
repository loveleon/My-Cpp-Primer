#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::cin;

int main() {
  vector<int> v;
  for (int i; cin >> i; v.push_back(i))
    ;
  for (auto it = v.cbegin(); it + 1 != v.end(); ++it)
    cout << *it + *(it + 1) << " ";
  cout << endl;
  for (auto ileft = v.cbegin(), iright = v.cend() - 1; ileft <= iright;
       ileft++, iright--)
    cout << *ileft + *iright << " ";
  cout << endl;
  return 0;
}