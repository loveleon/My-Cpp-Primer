#ifndef _EX12_02_H__
#define _EX12_02_H__
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using std::vector;
using std::cout;
using std::endl;
using std::string;
class StrBlob{
    public:
        typedef vector<string>::size_type size_type;
    public:
        StrBlob():data(std::make_shared<vector<string>>()){}
        StrBlob(std::initializer_list<string> il):data(std::make_shared<vector<string>>(il)){}
        size_type size()const {
            return data->size();
        }
        bool empty(){return data->empty();}
        void push_back(string str);
        void pop_back();

        string& front();
        const string& front() const;
        string& back();
        const string& back()const;
    private:
        std::shared_ptr<vector<string>> data;
        void check(size_type sz,string str)const;
};
#endif
