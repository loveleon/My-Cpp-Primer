#include <list>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	list<const char *> lst = {"123","456","789","101112"};
	vector<std::string> vec(lst.begin(),lst.end());
	vector<std::string> vec2;
	vec2.assign(lst.begin(),lst.end());
	for(auto str : vec)
		cout << str << " ";
	cout<<endl;
	for(auto str2 : vec2)
		cout << str2 << " ";
	cout << endl;
	return 0;
}