#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec{1,2,3,4,5,6,7,8,9};
	vector<int>::iterator it = vec.begin(),mid = vec.begin() + vec.size()/2;
	while(it != mid)
	{
		if(*it == 2)
			vec.insert(it,2*2);
	}
	for(auto i : vec)
		cout << i << " ";
	cout << endl;
	return 0;
}