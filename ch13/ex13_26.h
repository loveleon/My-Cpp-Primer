#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
using std::vector;
using std::string;
using std::shared_ptr;
using std::ifstream;
using std::ostream;
class StrBlob;
std::ostream & print(std::ostream &out,StrBlob & sb);
class StrBlob{
    friend std::ostream & print(std::ostream &out, StrBlob &sb);
    public:
        StrBlob(ifstream &file);
        StrBlob(const StrBlob &sb);
        StrBlob & operator=(StrBlob &rt);
        ~StrBlob();

    private:
        std::shared_ptr<vector<string>> data;
};
