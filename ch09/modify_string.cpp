#include <iostream>
#include <string>
using namespace std;

int main() {
	const char* p = "Stately, plump Buck";
	string s;
	s.assign(p, 7);
	// string str;
	s.insert(s.size(), p + 7);
	// str.insert(str.size(), p + 7);
	cout << "string(s) :" << s << endl;
	// cout << "string(str):" << str << endl;

	// str1 str2
	string str1 = "some string";
	string str2 = "some other string";
	str1.insert(0, str2, 0, str2.size());
	cout << "str1 after insert ,it changes to : " << str1 << endl;

	return 0;
}