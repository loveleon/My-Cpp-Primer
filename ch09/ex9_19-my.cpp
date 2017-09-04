#include <list>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	list<string> lst;
	string str;
	while(cin >> str)
	{
		lst.push_back(str);
	}
	for(auto it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}