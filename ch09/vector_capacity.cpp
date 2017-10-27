#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  //atoi
using std::endl;
using std::cout;
using std::vector;

// argv1--first insert total numbers,
// argv2--second insert total numbers.
int main(int argc, char *argv[]) {
  std::vector<int> v;
  cout << "before insert ,vector<int> capacity :" << v.capacity() << endl;
  for (int i = 0; i < atoi(argv[1]); i++) v.push_back(i);
  std::cout << "vector<int> size :" << v.size() << endl;

  cout << "after insert ,vector<int> capacity :" << v.capacity() << endl;

  for (int j = 0; j < atoi(argv[2]); j++) v.push_back(j + atoi(argv[1]));

  cout << "after 2 insert, vector<int> capacity :" << v.capacity() << endl;

  // shrink_to_fit() since c++11
  v.shrink_to_fit();
  cout << "after shrink_to_fit , vector<int> capacity :" << v.capacity()
       << endl;

  return 0;
}