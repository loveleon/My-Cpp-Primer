#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//vector
	vector<char> vec;
	char tmp;
	cout << "Enter a string of characters including punctuation." << endl;
	// string str;
	// cin >> str;
	// char tmp;
	// while (str >> tmp)
	// // while(cin >> tmp)
	// // {

	// // }
	//for(string s; getline(cin,s);cout << endl;)
	for (string s;getline(cin,s);cout<< endl)
		for(auto &i : s)
			if(!ispunct(i)) cout << i;
}