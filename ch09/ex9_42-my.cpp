#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<char> v;
	v.reserve(8);
	for (int i = 0; i < 8; i++) {
		char c;
		cin >> c;
		v.push_back(c);
	}

	string str(v.cbegin(), v.cend());
	cout << "string :" << str << endl;
	// for (auto j : v) cout << j << " ";
	// cout << endl;
	return 0;
}