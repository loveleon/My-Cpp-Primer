#include "common.h"

int main(){
    map<string,list<int>> mWordNum;
    ifstream inFile("../ex11_9_input.txt",inFile.in);
    string line;
    if(inFile.is_open()){
        while(getline(inFile,line)){
            static int lineNum = 0;
            ++lineNum;
            istringstream words(line);
            string word;
            while(words >> word){
                mWordNum[word].push_back(lineNum);
            }
        }
    }

    for(const auto& str : mWordNum){
        cout << str.first << " ";
        for(auto& num : str.second){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
