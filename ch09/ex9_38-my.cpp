#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	vector<int> v;
	for (auto i = 0; cin >> i; v.push_back(i)) cout << v.capacity() << endl;
	return 0;
}