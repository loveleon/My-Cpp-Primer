#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>

using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::istringstream;
using std::shared_ptr;
using std::string;
using std::vector;

int main(
        ){
    shared_ptr<vector<string>> sp = std::make_shared<vector<string>>();
 //   vector<string> sp;
    ifstream inFile("../test_vector.cpp",inFile.in);
    if(inFile){
        string line;
        while(getline(inFile,line)){
            sp->push_back(line);
                }
    }
    for_each(sp->begin(),sp->end(),[](const string &str){cout << str << endl;});
//    for_each(sp.begin(),sp.end(),[](const string &str){cout << str << endl;});
    return 0;
}
