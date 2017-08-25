#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  // using index = int ia[4];
  using index = int[4];
  for (index &p : ia)
    for (int &q : p) cout << q << " ";
  cout << endl;
  return 0;
}