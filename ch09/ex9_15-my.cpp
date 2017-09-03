#include <vector>
#include <iostream>
using namespace std;

int main()
{
	bool is_equal = false;
	vector<int> v1{1,2,3,4,5,6};
	vector<int> v2{1,2,3,4,5,6};
	if(v1 == v2)
		cout << " v1 == v2 is true" << endl;
	else
		cout << " v1 != v2 is true" << endl;
	if(v1.size() != v2.size())
		cout << "v1 != v2" << endl;
	else{
		for(auto it1 = v1.begin(),it2 = v2.begin();it1 != v1.end() && it2 != v2.end();++it1,++it2)
			if(*it1 == *it2)
				is_equal = true;
			else{
				is_equal = false;
				break;
			}
	}
	cout << "v1 == v2 is " << boolalpha << (is_equal == true) << endl;
	return 0;
}