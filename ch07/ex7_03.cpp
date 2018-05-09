#include "ex7_02.h"

int main(){
    Sales_data total;
    if(cin >>total.bookNo >> total.units_sold >> total.revenue){
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> trans.revenue){
            if(total.bookNo == trans.bookNo){
                total.combine(trans);
            }else{
                cout << total.isbn() <<" " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.isbn() << " " <<  total.units_sold <<" " << total.revenue << endl;
    }else{
        std::cerr << "invalid input." << endl;
    }

    return 0;
}

