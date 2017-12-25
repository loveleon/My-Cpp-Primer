#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::endl;
// using std::vector;
using std::string;

int main(int argc, char *argv[]) {
	string numbers("0123456789"), name("r2d2");

	string::size_type pos = numbers.find(name);
	if (pos == string::npos) {
		cout << "can't find " << name << " in " << numbers << endl;
	}

	return 0;
}