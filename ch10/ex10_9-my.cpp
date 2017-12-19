#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void elimDups(vector<string> &v)
{
    string str;
    for(;cin >> str;v.push_back(str));
    std::sort(v.begin(),v.end());
    auto it = std::unique(v.begin(),v.end());
    v.erase(it,v.end());
    for (auto i : v)
        cout << i << " ";
    cout <<endl;
}

int main(){
    vector<string> v(10);
    elimDups(v);
    return 0;
}
