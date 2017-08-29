#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef std::vector<int>::iterator iter;
bool isfound(iter start, iter end, int found)
{
	bool is_found = false;
	for(auto it =start; it != end;	++it)
	{
		if(*it == found){
			is_found = true;
			break;
		}
		else{
			is_found= false;
		}
	}
	cout << "is found is :" << std::boolalpha  << is_found <<endl ;
}

int main(int argc,char* argv[])
{
	vector<int> vec;
	int found;
	for(int i;cin >> i;vec.push_back(i))
		;
	found = atoi(argv[1]);
	isfound(vec.begin(),vec.end(),found);
	return 0;

}

