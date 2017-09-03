#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	bool is_equal = false;
	list<int>::iterator it1;
	vector<int>::iterator it2;
	list<int> lst{1,2,3,4,5,6};
	vector<int> vec{1,2,3,4,5,6};

	if(lst.size() != vec.size())
		is_equal = false;
	else{
		for( it1 = lst.begin(),it2 = vec.begin();it1 != lst.end() && it2 != vec.end(); ++it1,++it2){
		// for(auto it1 = lst.begin(),it2 = vec.begin();it1 != lst.end() && it2 != vec.end(); ++it1,++it2){
			if(*it1 == *it2)
				is_equal = true;
			else{
				is_equal = false;
				break;
			}
		}
	}
	cout << "list == vector is " << boolalpha << (is_equal == true) << endl;
	return 0;
}