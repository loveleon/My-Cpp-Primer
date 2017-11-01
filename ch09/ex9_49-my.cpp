#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <cassert>

using namespace std;

typedef vector<string> vec_string;
typedef list<string> list_string;

vec_string find_MR_right_word(vec_string &v, std::string s) {
	vec_string return_vec;
	for (auto str : v) {
		if (auto pos = str.find_first_of(s) == string::npos) {
			return_vec.push_back(str);
		}
	}

	return return_vec;
}

static void print(vec_string v) {
	for (auto str : v) {
		std::cout << str << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	//判断文件打开成功
	ifstream file("./ex9_49-my.cpp", ios::in);
	// ifstream file("./ex9_49-test-file", ios::in);
	assert(file);

	string word;
	// list_string list;
	vec_string v;
	while (file >> word) {
		v.push_back(word);
	}

	string str = "bdfghijklpqty";

	print(find_MR_right_word(v, str));

	return 0;
}