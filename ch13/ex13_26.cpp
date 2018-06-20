#include "ex13_26.h"

StrBlob::StrBlob(ifstream &file){
    data = std::make_shared<vector<string>>();
    if(file){
        for(string line;getline(file,line);)
            data->push_back(line);
    }
}

StrBlob::StrBlob(const StrBlob &rt){
    data = std::make_shared<vector<string>>(*rt.data);
}

StrBlob & StrBlob::operator=(StrBlob &rt){
    auto sb = std::make_shared<vector<string>>(*rt.data);
    data = sb;
    return *this;
}

StrBlob::~StrBlob(){
    std::cout << "~StrBlob called." << std::endl;
}

std::ostream &print(std::ostream &out,StrBlob &sb){
    for(const auto str : *sb.data)
        out << str << std::endl;
    return out;
}
