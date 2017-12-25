#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	std::vector<double> v = {1.1, 0.5, 3.3};
	cout << "total double :" << accumulate(v.cbegin(), v.cend(), 0) << endl;
	cout << "total double(2):" << accumulate(v.cbegin(), v.cend(), 0.0) << endl;
	return 0;
}