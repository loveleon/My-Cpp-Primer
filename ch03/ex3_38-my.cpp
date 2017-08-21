#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1("im string one");
	string str2("im string two");
	if(str1 == str2)
		std::cout << "str1 == str2" <<std::endl;
	else
		std::cout << "str1 != str2" <<std::endl;

	int i=0;
	char cstr1[10]={'i','m','s','t','1'};
	char cstr2[10]={'i','m','s','t','1'};
	while(cstr1[i] && cstr2[i])
		if(cstr1[i] == cstr2[i])
			;
		else
			break;
		i++;
	}