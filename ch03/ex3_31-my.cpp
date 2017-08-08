#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  int a[10];
  for (auto i = 0; i < 10; i++) a[i] = i;
  for (auto out : a) cout << out << endl;
  return 0;
}