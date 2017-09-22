#include <iostream>
#include <forward_list>
#include <string>

using std::endl;
using std::cout;
using std::string;
using std::forward_list;

bool insert_forward_list(forward_list<string>& flst, string str1, string str2) {
	auto prev = flst.before_begin();
	auto cur = flst.begin();
	// auto itStrA = flst.find(str1);
	while (cur != flst.end()) {
		if (*cur == str1) {
			flst.insert_after(cur, str2);
			return true;
		} else {
			prev = cur;
			++cur;
			// continue;
		}
	}

	flst.insert_after(prev, str2);

	return true;
}

void print(forward_list<string>& flst, string str1) {
	cout << "insert after string " << str1 << "..." << endl;
	for (auto f : flst) cout << f << " ";
	cout << endl << endl;
}

int main() {
	forward_list<string> flst = {"he", "she", "it", "corlor"};
	auto ret = insert_forward_list(flst, "she", "done");
	cout << std::boolalpha << ret << endl;
	print(flst, "she");
	auto ret2 = insert_forward_list(flst, "she", "done2");
	print(flst, "she");
	auto ret3 = insert_forward_list(flst, "im", "done3");
	print(flst, "im");

	return 0;
}