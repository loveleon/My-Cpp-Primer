#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

typedef list<string>::iterator iter;
list<string> lst;

extern int Count(iter start, iter end, string str);

int main() {
	// input
	cout << "input:" << endl;
	for (string str; cin >> str; lst.push_back(str))
		;
	cout << "number:" << Count(lst.begin(), lst.end(), "123cxh") << endl;
	return 0;
}

int Count(iter start, iter end, string str) {
	int num = count(start, end, str);
	return num;
}