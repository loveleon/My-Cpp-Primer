#include <deque>
#include <string>
#include <iostream>
 using namespace std;

 int main()
 {
 	deque<string> deq;
 	string str;
 	while(cin >> str)
 	{
 		deq.push_back(str);
 	}
 	for(auto it = deq.begin(); it != deq.end(); ++it)
 	{
 		cout << *it << " ";
 	}
 	cout << endl;
 	return 0;
 }