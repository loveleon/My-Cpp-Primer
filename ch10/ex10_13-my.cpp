#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;

bool LengthGtFive(string str){
    return str.size() >= 5;
}

int main(){
    vector<string> v = {"123456","abc","asdfdsfd","sfasdfasd","add","add","dsafsdfasd"};
   auto it =  std::partition(v.begin(),v.end(),LengthGtFive);
   for(auto iter = v.begin();iter != it;iter++){
       cout<< *iter << " ";

   }
   cout << endl;

   return 0;
}
