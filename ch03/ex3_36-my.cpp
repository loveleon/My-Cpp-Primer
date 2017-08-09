#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

// template<T>
bool is_same(int* am, int* an, int nsize) {
  bool ret = false;
  cout << "sizeof(am):" << sizeof(am) << endl;
  cout << "sizeof(int*):" << sizeof(int*) << endl;
  assert(am && an);
  // while (*am++ == *an++)
  while (nsize--) {
    if (*am++ == *an++)
      ret = true;
    else {
      ret = false;
      break;
    }
  }
  return ret;
}

// this is an error function .bec the loop condition will not abnormal
bool is_same_vector(vector<int>& am, vector<int>& an) {
  auto ret = 0;
  for (auto im = am.begin(), in = an.begin();
       (im != am.end()) || (in != an.end()); ++im, ++in) {
    if (*im == *in) {
      ret = 1;
    } else {
      ret = 0;
      break;
    }
  }
  return ret;
}

bool is_same_vector2(vector<int>& am, vector<int>& an) {
  if (am == an)
    return 1;
  else
    return 0;
}

int main() {
  vector<int> m = {1, 2, 3, 4};  //, 4, 5, 6, 7};
  vector<int> n = {1, 2, 3};     //, 3, 4, 5, 6};
  // auto same = is_same_vector(m, n);
  auto same = is_same_vector2(m, n);
  cout << "vector m,n is (0-not same,1-same):" << same << endl;
  int a[4] = {1, 2, 3, 4};  //, 5, 6, 7, 8, 0, 0};
  int b[4] = {1, 2, 3, 4};  //, 5, 6, 7, 8, 0, 0};
  bool ret = is_same(a, b, sizeof(a) / sizeof(int));
  cout << "ret=" << ret << endl;
  return 0;
}