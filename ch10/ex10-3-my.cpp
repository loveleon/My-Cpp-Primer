// Exercise 10.3:
// Use accumulate to sum the elements in a vector<int>.
//
// Exercise 10.4:
// Assuming v is a vector<double>, what, if anything,
// is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?
//  Check below.

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef vector<int> vec_int;
// typedef vec_int::iterator iter;
typedef vec_int::const_iterator iter;

int Accumulate(iter start, iter end, int num) {
	return std::accumulate(start, end, num);
}

int main() {
	cout << "input:" << endl;
	vec_int v;
	for (int i; cin >> i; v.push_back(i))
		;
	int num = 0;
	cout << "total :" << Accumulate(v.cbegin(), v.cend(), num) << endl;

	return 0;
}