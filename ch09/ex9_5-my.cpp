#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef std::vector<int>::iterator iter;
iter isfound(iter start, iter end, int found)
{
	bool is_found = false;
	for(auto it =start; it != end;	++it)
	{
		if(*it == found){
			is_found = true;
			return it;
		}
		else{
			is_found= false;
		}
	}
	return end;
}

int main(int argc,char* argv[])
{
	vector<int> vec;
	int found;
	iter ret;
	for(int i;cin >> i;vec.push_back(i))
		;
	found = atoi(argv[1]);
	ret = isfound(vec.begin(),vec.end(),found);
	if(ret != vec.end())
		cout << "is founded ..."<<endl;
	else
		cout << "is not founed ..." <<endl;
	return 0;
}

