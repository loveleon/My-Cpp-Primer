#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	
	for(string s; getline(cin,s);cout<<endl)
	{
		for(auto &i : s)
		{	
			i = 'X';
		}
		for (auto &j : s)
			cout << j;
	}
	cout << endl;
	return 0;
}
