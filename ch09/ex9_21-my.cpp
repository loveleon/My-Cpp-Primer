#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	vector<int>::iterator it;
	int iTmp;
	while(cin >> iTmp)
	{
		it = vec.insert(it,iTmp);
	}
	for(auto itvec : vec)
		cout << itvec << " ";
	cout << endl;
	return 0;
}