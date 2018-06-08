#include "ex12_27.h"

int main(){
    ifstream infile("../ex12_27.h",infile.in);
    TextQuery q(infile);
    string msg;
    while(true){
        cout << "input lookup keyword:" << endl;
        cin >> msg;
        if(cin || msg == static_cast<string>("q"))
            break;
        auto rst = q.query(msg);
        cout << "you input msg:" << msg << endl;
        print(cout ,rst) << endl;
    }
    return 0;
}
