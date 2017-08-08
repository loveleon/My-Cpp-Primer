#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Read a sequence of words from cin and store the values a
// vector. After you’ve read all the words, process the vector and change
// each word to uppercase. Print the transformed elements, eight words to a
// line.
int main() {
  vector<string> vec;
  for (string str; cin >> str; vec.push_back(str))
    ;
  for (auto &str : vec)
    for (auto &c : str) c = toupper(c);
  for (string::size_type i = 0; i < vec.size(); ++i) {
    if (i != 0 && i % 8 == 0) cout << endl;
    cout << vec[i] << " ";
  }
}