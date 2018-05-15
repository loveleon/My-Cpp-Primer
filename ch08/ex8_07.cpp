#include "ex8_06.h"

int main(){
    Sales_data total;
    //1.open file
    ifstream inFile("../Sales_data.txt");
    ofstream outFile;
    outFile.open("../Sales_data_out.txt");
    if(inFile){
        if(read(inFile,total)){
                Sales_data trans;
                while(read(inFile,trans)){
                    if(total.isbn() == trans.isbn()){
                        total.combine(trans);
                    }else{
                        if(outFile.is_open()){
                            print(outFile,total) << std::endl;
                        }
                        total = trans;
                    }
                }
                if(outFile.is_open()){
                    print(outFile,total) << std::endl;
                }
        }else{
            cerr << "Read empty data!" << std::endl;
            if(outFile.is_open()){
                outFile << "Read empty data!" << std::endl;
            }
        }
    }
    if(outFile.is_open()){
        outFile << "outFile close." << std::endl;
        outFile.close();
    }

    return 0;
}
