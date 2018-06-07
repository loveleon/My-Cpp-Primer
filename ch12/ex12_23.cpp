#include <iostream>
#include <cstring>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::string;

char * StrCat(const char *first, const char *sec){
    char *all = new char[strlen(first)+strlen(sec)+1];
    strcat(all,first);
    strcat(all,sec);
    return all;
}

string StrCat2(const string &first, const string &sec){
    string tmp = first+sec;
    return (tmp);
}

int main(){
    const char * first = "123456";
    const char * sec = "7891011";
    unique_ptr<char []> u(StrCat(first,sec));
    for(unsigned i=0;i<strlen(first)+strlen(sec)+1;i++)
    {
        cout << u[i];
    }
    cout << endl;
    cout << "string:" << endl;
    const string str1("abcdef");
    const string str2("ghijklm");
    cout << StrCat2(str1,str2);
    cout << endl;
}
