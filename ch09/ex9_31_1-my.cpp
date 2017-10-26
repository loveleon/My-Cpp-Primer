#include <list>
#include <iostream>
#include <string>
using namespace std;

// even -偶数 odd-奇数
void remove_even_and_double_odd(list<int>& lst) {
	list<int>::iterator it = lst.begin();

	while (it != lst.end()) {
		if (*it & 0x01) {
			it = lst.insert(it, *it);
			std::advance(it, 2);
		} else {
			it = lst.erase(it);
		}
	}
}

int main() {
	list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	remove_even_and_double_odd(lst);
	for (auto i : lst) std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}