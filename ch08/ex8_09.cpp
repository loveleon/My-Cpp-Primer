#include "ex8_01.h"
#include <sstream>
using std::istringstream;
using std::cout;
using std::endl;
using std::string;using std::cin;
int main(){
    cout << "input a line string:" << endl;
    string tmp;
    getline(std::cin,tmp);
    istringstream is(tmp);
    read(is);

    return 0;

}
