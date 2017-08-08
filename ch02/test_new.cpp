#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	long long *p = new long long [1600];
	memset(p , 0, 2000);
	p[0] = 1200;
	std::cout << p[0] << std::endl;
	return 0;
}