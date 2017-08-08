#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  std::vector<int> v;
  for (int i; cin >> i; v.push_back(i))
    ;

  for (auto it = v.begin(); it != v.end(); ++it) cout << *it << " ";
  cout << "size:" << v.size() << endl;
  return 0;
}