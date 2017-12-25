// Exercise 9.50:
// Write a program to process a vector<string>s whose elements represent
// integral values.
// Produce the sum of all the elements in that vector.
// Change the program so that it sums of strings that represent floating-point
// values.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void make_vector_string(vector<string> &vec) {
	for (string str; cin >> str; vec.push_back(str))
		;
}

template <typename T>
void print(vector<T> &vec) {
	for (auto str : vec) cout << str << " ";
	cout << endl;
}

vector<int> StringToIntXX(vector<string> &vec) {
	vector<int> vec_int;
	for (auto &str : vec) {
		auto tmp = std::stoi(str);
		vec_int.push_back(tmp);
	}
	return vec_int;
}

template <typename T>
T caculate(vector<T> &vec) {
	T tmp{0};

	for (auto &i : vec) {
		tmp += i;
	}
	return tmp;
}

int main(int argc, char *argv[]) {
	vector<string> vec;
	make_vector_string(vec);
	print<string>(vec);

	auto vec_int = StringToIntXX(vec);
	print<int>(vec_int);

	int cal = caculate<int>(vec_int);
	// auto i = caculate<int>(vec_int);
	cout << cal << endl;

	return 0;
}