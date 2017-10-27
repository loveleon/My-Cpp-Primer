#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	std::vector<string> v;
	string str;
	v.reserve(50);  // v.reserve(5);
	while (cin >> str) {
		v.push_back(str);
		if (v.size() == v.capacity()) {
			cout << "size == capacity, " << v.size() << " == " << v.capacity()
			     << endl;
		}
	}
	v.resize(v.size() + v.size() / 2);
	cout << "size : " << v.size() << ",capacity :" << v.capacity() << endl;
	v.resize(1);
	cout << "size : " << v.size() << ",capacity :" << v.capacity() << endl;
	for (auto sTemp : v) cout << sTemp << " ";
	cout << endl;

	return 0;
}