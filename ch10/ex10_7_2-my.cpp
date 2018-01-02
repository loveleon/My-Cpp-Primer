#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
//using namespace std;
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::cin;


int main(){
    vector<int> vec;
    vec.resize(10);

    fill_n(vec.begin(),10,0);

    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    return 0;
}
