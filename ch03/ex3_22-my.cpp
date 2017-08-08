#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<string> v;
  for (string str; cin >> str; v.push_back(str))
    ;
  for (auto &tmp : v)
    for (auto &c : tmp) c = toupper(c);
  for (auto it = v.cbegin(); it != v.end(); ++it)
    cout << *it << (it != v.end() - 1 ? " " : "endl");
  return 0;
}