#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
// https://github.com/Mooophy/Cpp-Primer/issues/227
// As we know, c-style strings cannot be compared using == and < and >, 'casue
// these relational operators compare addresses in pointers rather than strings
// represented by char pointers.

//我们知道，c风格的字符串不能用==和<和>来比较，这些关系运算符比较指针中的地址，而不是用char指针表示的字符串。
//因此指针指向的相同内容的文字共享相同的内存，但是数组中的文字单独存储。

int main() {
	char *a[3] = {"123", "456", "789"};
	char *b[4] = {"123", "456", "789", "89"};
	cout << std::boolalpha << std::equal(begin(a), end(a), begin(b)) << endl;

	char c[3][2] = {"a", "b", "c"};
	char d[3][2] = {"a", "b", "c"};
	cout << std::boolalpha << std::equal(begin(c), end(c), begin(d)) << endl;
	return 0;
}