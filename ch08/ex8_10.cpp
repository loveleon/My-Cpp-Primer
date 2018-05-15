//read a whole file. one line storage into a vector.Then using istringstream read a word from vector.
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using std::cout;using std::cin;using std::istringstream;using std::vector;
using std::ifstream;using std::string;
using std::endl;using std::ofstream;

int main(){
    ifstream in("../ex8_10.cpp");
    ofstream out1("../out1.txt");
    ofstream out2("../out2.txt");
    vector<string> vec;
    if(in.is_open()){
        string line;
        while(getline(in,line)){
            vec.push_back(line);
            vec.push_back(" ");
        }
        in.close();
    }

    string tmp;
    //istringstream is(tmp);
    for(auto& tmp : vec){
        out1 << tmp << " ";
        istringstream is(tmp);
        string word;
        while(is >> word ){
            cout << word << " ";
            out2 << word << " ";
        }
    }

   // for(vector<string>::size_type i=0; i<vec.size();i++){
   //     cout << vec[i] << endl;
   // }

    out1.close();
    out2.close();
    cout << endl;
    return 0;
}
