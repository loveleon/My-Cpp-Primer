#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
*/
// string find_replace_string(string s, string oldVal, string newVal) {
// 	string::iterator it = s.begin();
// 	while (it != s.end()) {
// 		string::size_type pos = s.find(oldVal);  // return
// string::size_type
// 		if (pos != std::string::npos) {
// 			it = s.erase(
// 			         pos,
// 			         oldVal.size());  // earse(size_type
// index,size_type
// num = npos)
// 			for (auto ch : newVal) {
// 				it = s.inert(it, ch);  // reset 'it' (when use
// `erase`
// or
// `insert`)
// 			}
// 		} else {
// 			it++;
// 		}
// 	}

// 	return s;
// }

string find_insert_erase(string s, string oldVal, string newVal) {
	for (auto cur = s.begin(); cur <= s.end() - oldVal.size();) {  /// '=' ???
		if (oldVal == string{cur, cur + oldVal.size()}) {
			cout << string{cur, cur + oldVal.size()} << endl;
			cur = s.erase(cur, cur + oldVal.size());
			for (int i = 0; i < newVal.size(); i++) {
				cur = s.insert(cur, newVal[i]);
			}
			// cur = s.insert(cur, newVal.begin(), newVal.end());
			cur += newVal.size();  // cur
		} else {
			++cur;
		}
	}
}

void print(string str) { cout << str << endl; }

int main(int argc, char *argv[]) {
	string s = "hello ,thsi is a test file.And thsi file will modify.";
	string oldVal = "thsi";
	string newVal = "this";
	print(find_insert_erase(s, oldVal, newVal));

	return 0;
}