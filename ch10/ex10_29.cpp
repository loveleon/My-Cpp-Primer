#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int main(){
    std::ifstream ifile;
    vector<string> vec;
    ifile.open("../ex10_29.cpp",ifile.in);
    std::istream_iterator<string> in(ifile),eof;
    std::ostream_iterator<string> out(cout," ");
    copy(in,eof,back_inserter(vec));
    copy(vec.cbegin(),vec.cend(),out);
//    for_each(vec.cbegin(),vec.cend(),[](const string &str){cout << str << " ";});
    cout << endl;
    return 0;
}
