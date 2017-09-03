#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	vector<string> vec;
	string tmp;
	auto it = vec.begin();
	while(cin >> tmp)
	{
		it = vec.insert(it,tmp);
	}
	for(auto it2 : vec)
		cout << it2 << " ";
	cout << endl;
	return 0;
}