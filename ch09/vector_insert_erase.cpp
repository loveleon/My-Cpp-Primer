#include <vector>
#include <iostream>
using namespace std;
// page 316
static void insert_erase() {
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	vector<int>::iterator it = v.begin();  // not 'cbegin'

	while (it != v.end()) {
		//在奇数位置插入元素，删除偶数
		if (*it % 2) {
			it = v.insert(it, *it);
			it += 2;
		} else {
			it = v.erase(it);
		}
	}

	for (auto i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

static void insert_after_item() {
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		++it;  // it ++ ,insert the new value after the item.
		it = v.insert(it, 0);
		++it;  // jump the new inserted item.
	}
	for (auto i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main() {
	// insert_erase();
	insert_after_item();
	return 0;
}