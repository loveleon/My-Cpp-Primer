#include "ex12_27.h"

int main(){
    //ifstream infile("../ex12_28_input.txt",infile.in);
    ifstream infile("../ex12_27.h",infile.in);
    TextQuery q(infile);
    string msg;
    while(true){
        cout << "input lookup keyword:" << endl;
        cin >> msg;
        auto newmsg = string("q");
        cout << newmsg << endl;
        if(!cin || msg == newmsg)
            break;
        auto rst = q.query(msg);
        cout << "you input msg:" << msg << endl;
        print(cout ,rst) << endl;
    }
    return 0;
}
