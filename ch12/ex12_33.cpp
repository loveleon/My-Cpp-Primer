#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <functional>
#include "ex12_33.h"

using std::vector;using std::map;using std::istringstream;using std::ifstream;using std::cout;using std::cin;using std::endl;
using std::string;using std::set;

int main(){
    ifstream infile("../ex12_33.cpp",infile.in);
    if(!infile){
        std::cerr << "Open file error! " << endl;
        return -1;
    }

    TextQuery q(infile);
    string msg;
    while(cin >> msg){
        if(!cin || msg == string("q"))
            break;
        auto qr = q.query(msg);

        print(std::cout, qr) << endl;
    }
    return 0;
}
