#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc,char* argv[])
{
	vector<int> vec(10,-1);
	//10 item with -1 initerliazed
	vector<int> vec2(10);
	//10 item defualt 0
	vector<int> vec3={1,2,3,4,5,6};
	//列表初始化

	vector<int> vec4(vec3);
	//with other vector init

	vector<int> vec5(vec4.begin(),vec4.end());

	vector<int> vec6;//default 0
	return 0;
}