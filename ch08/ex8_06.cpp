#include "ex8_06.h"

int main(){
    Sales_data total;
    //1.open file
    ifstream inFile("../Sales_data.txt");
    if(inFile){
        if(read(inFile,total)){
                Sales_data trans;
                while(read(inFile,trans)){
                    if(total.isbn() == trans.isbn()){
                        total.combine(trans);
                    }else{
                        print(std::cout,total) << std::endl;;
                        total = trans;
                    }
                }
                print(std::cout,total) << std::endl;
        }else{
            cerr << "Read empty data!" << std::endl;
        }
    }

    return 0;
}
