#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> v{42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};
  // for (auto it = v.cbegin(); it != v.end(); it++)
  // for (auto)

  vector<using int> scores;
  for (int grade; cin >> grade;) ++*(scores.begin() + grade / 10);
  for (auto s : scores) cout << s << " " cout << endl;
  return 0
}