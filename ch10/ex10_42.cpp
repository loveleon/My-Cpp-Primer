#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::list;
using std::endl;
using std::cout;
using std::string;

void elimDups(list<string> &lst){
    lst.sort();//sort(lst.begin(),lst.end());
    lst.unique();
}

void print(list<string> &lst){
    for_each(lst.cbegin(),lst.cend(),[](const string &str){cout << str << " ";});
    cout << endl;
}

int main(){
    list<string> lst = {"cxh","qwe","cxh","qwe","asf","asf","name","try","name"};
    elimDups(lst);
    print(lst);

    return 0;
}
