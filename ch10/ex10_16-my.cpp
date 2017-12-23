#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
using std::sort;
using std::cout;
using std::endl;
using std::unique;
using std::string;

void eliDepum(vector<string> &v)
{
    sort(v.begin(),v.end());//,[]( string &a,string& b){return a.size() < b.size();});
    //sort(v.begin(),v.end(),[]( string &a,string& b){return a.size() < b.size();});
    auto iter = unique(v.begin(),v.end());
    v.erase(iter,v.end());
    for(auto i : v)
        std::cout << i << " ";
    std::cout <<endl;
}

void biggies(vector<string> &v,string::size_type s){
    std::stable_sort(v.begin(),v.end(),[](const string &a,const string &b){return a.size() < b.size();});
    for (auto i : v)
        cout << i << " ";
    cout <<endl;
   auto iter =  std::find_if(v.begin(),v.end(),[s](string str) {return str.size() >= s;});
   auto count = v.end() - iter;
   std::cout << "count -- length greater than " << s << "is "<< count << endl;
   for_each(iter,v.end(),[](string str){cout << str << " ";});
   cout << endl;
}

int main(){
    vector<string> v = {"123","4534534","123","adsfadad","12","adsfadad","789","789","a"};
    eliDepum(v);
    biggies(v,3);

    return 0;
}
