#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
vector<int>::iterator it;
typedef vector<int>::iterator Iter;

extern int Count(Iter start, Iter end, int value);

int main() {
	cout << "input (int):";
	// for_each(int i; cin >> i; v.push_back(i));
	for (auto i = 0; cin >> i; v.push_back(i))
		;

	cout << "input value:";
	int value = 10;
	// cin >> value;
	int num = Count(v.begin(), v.end(), value);
	cout << "number:" << num << endl;
	return 0;
}

int Count(Iter start, Iter end, int value) {
	auto num = count(start, end, value);
	return num;
}