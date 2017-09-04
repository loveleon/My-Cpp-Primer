#include <deque>
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	list<int> lst{1,2,3,4,5,6,7,8,9,10,11,13};
	deque<int> deq1;
	deque<int> deq2;
	for(auto it = lst.begin(); it != lst.end(); ++it)
	{
		if(*it % 2)
			deq1.push_back(*it);
		else
			deq2.push_back(*it);
	}
	for(auto it1 : deq1)
		cout << it1 << " ";
	cout << endl;
	for(auto it2 : deq2)
		cout << it2 << " ";
	cout << endl;
	return 0;
}