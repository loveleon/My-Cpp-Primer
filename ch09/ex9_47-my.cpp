#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<char> v_char;
typedef vector<string> v_str;

/*
*param str :input  待检验字符串
*param args : input 包含规则字符集
*/
static v_char find_chars(string str, string args) {
	v_char v;

	string::size_type pos = 0;
	while ((pos = str.find_first_of(args, pos)) != string::npos) {
		v.push_back(str[pos]);
		// std::cout << str[pos] << " ";
		pos++;
	}

	return v;
}

static v_char find_chars_with_exclude(string str, string args) {
	v_char v;

	string::size_type pos = 0;
	while ((pos = str.find_first_not_of(args, pos)) != string::npos) {
		v.push_back(str[pos]);
		pos++;
	}
	return v;
}

static void print(v_char &&v) {
	for (auto c : v) std::cout << c << " ";
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	string args_num = "0123456789";
	string args_str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string str = "ab2c03d7R4E6";
	// find num
	print(find_chars(str, args_num));
	print(find_chars_with_exclude(str, args_str));

	// find string
	print(find_chars(str, args_str));
	print(find_chars_with_exclude(str, args_num));

	return 0;
}