#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<int> vec{11, 22, 33, 44, 55};
  // auto it = vec.erase(vec.begin(), vec.begin());  // return the first item
  // auto it = vec.erase(vec.begin(), vec.begin() + 2);//return the begin() + 2
  // item
  auto it = vec.erase(vec.end(), vec.end());  // return the first item iterator
  auto itVecEnd = vec.begin();
  // auto it = vec.erase(vec.begin(), --(vec.end()));  // return the last item
  // auto it = vec.erase(vec.begin(),
  // vec.end());  // return the begin/first item iterator
  cout << *it << "|" << endl;
  if (it == itVecEnd) cout << "return the begin iterator ,why ?" << endl;
  for (auto itAfterDel = vec.begin(); itAfterDel != vec.end(); ++itAfterDel)
    cout << *itAfterDel << endl;
  return 0;
}