#include <forward_list>
#include <iostream>

using std::advance;
using std::forward_list;
using std::cout;
using std::endl;

// forward_list
// odd - 奇数 even-偶数
static void remove_even_and_double_odd(forward_list<int>& fwd_lst) {
	// forward_list<int>::iterator it = fwd_lst.begin();
	for (auto cur = fwd_lst.begin(), prev = fwd_lst.before_begin();
	        cur != fwd_lst.end();) {
		if (*cur & 0x01) {
			cur = fwd_lst.insert_after(prev, *cur);
			advance(prev, 2);
			advance(cur, 2);
		} else {
			cur = fwd_lst.erase_after(prev);
		}
	}
}

int main() {
	forward_list<int> fwd_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	remove_even_and_double_odd(fwd_list);
	for (auto i : fwd_list) cout << i << " ";
	cout << endl;

	return 0;
}