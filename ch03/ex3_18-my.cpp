#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  vector<int> ivec{42, 24};
  for (int i = 0; i < ivec.size(); i++) cout << ivec[i] << " ";
  cout << "size:" << ivec.size() << endl;
  return 0;
}