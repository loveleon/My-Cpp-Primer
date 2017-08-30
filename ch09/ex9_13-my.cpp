#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	list<int> lst={1,2,3,4,5,6};
	vector<double> vec(lst.begin(),lst.end());
	for(auto &i : vec)
		cout << i << " ";
	cout << endl;
	return 0;
}