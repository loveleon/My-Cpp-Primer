#include <iostream>
#include <string>
using namespace std;

int main() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int* const p = a;
  for (auto i = 0; i < 10; i++) {
    cout << *(p + i) << " ";
    *(p + i) = 0;
  }
  cout << endl;

  for (auto num : a) cout << num << " ";
  cout << endl;
  return 0;
}