#include <iostream>
#include <forward_list>
using namespace std;

int main() {
	forward_list<int> flst = {1, 2, 3, 4, 5, 6, 7, 8};
	auto prev = flst.before_begin();
	auto cur = flst.begin();
	while (cur != flst.end()) {
		if (*cur % 2) {
			cur = flst.erase_after(prev);
		} else {
			prev = cur;
			++cur;
		}
	}

	// print forward_list
	for (auto f : flst) {
		std::cout << f << " ";
	}
	std::cout << std::endl;

	return 0;
}