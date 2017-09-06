#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> vec;
  list<int> lst;
  for (auto it = begin(ia); it != end(ia); ++it) {
    // cout << *it << " ";
    vec.push_back(*it);
    lst.push_back(*it);
  }
  // cout << endl;

  for (auto itVec = vec.begin(); itVec != vec.end();) {
    if (!(*itVec % 2))
      // itVec = vec.erase(itVec);
      vec.erase(itVec);  // line20  and line21 return the same reult.
    else
      ++itVec;
  }
  // cout << endl;
  for (auto afterVec : vec) cout << afterVec << " ";
  cout << endl;

  for (auto itLst = lst.begin(); itLst != lst.end();) {
    // cout << *itLst << " ";
    if (*itLst % 2) itLst = lst.erase(itLst);  // right answer.
    // lst.erase(itLst);//make error warning
    else
      ++itLst;
  }
  // cout << endl;
  for (auto afterLst : lst) cout << afterLst << " ";
  cout << endl;

  return 0;
}