#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include <unordered_set>

using namespace std;

int main() {
  // vector<int> vec1(42, 10);
  vector<int> vec1(10, 42);
  vector<int> vec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  vector<int> vec3(10);
  for (int j; j < 10; vec3.push_back(42))
    ;
  cout << "vec1.size:" << vec1.size() << endl;
  cout << "vec2.size:" << vec2.size() << endl;
  cout << "vec3.size:" << vec3.size() << endl;
  return 0;
}