#include <iostream>
#include <vector>
#include <string>
#include <cstring>  //strlen

using namespace std;

// vector<char> --> string
int main(int argc, char *argv[]) {
	vector<char> v = {'a', 'b', 'c', 'd', 'e'};
	string str(v.cbegin(), v.cend());

	cout << "string:" << str << endl;

	return 0;
}