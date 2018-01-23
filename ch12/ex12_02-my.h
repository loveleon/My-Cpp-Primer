#include <initializer_list>
#include <exception>
#include <vector>
#include <string>
#include <iostream>
#include <memory>

using std::initializer_list;
using std::vector;
using std::string;

class StrBob{
    public:
    typedef std::vector<string>::size_type size_type;
    StrBob():data(std::make_shared<std::vector<string>>()){}
    StrBob(initializer_list<string> nil):data(std::make_shared<std::vector<string>>(nil)){}
    string& front(){
        check(0,"front of empty vector.");
        return data->front();
    }

    const string& front()const{
        return data->front();
    }

    string& back(){
        check(1,"back empty StrBob");
        return data->back();
    }
    const string& back()const{
        return data->back();
    }

    void pop_back(){
        data->pop_back();
    }

    void push_back(string str){
        data->push_back(str);
    }

    size_type size(){
        return data->size();
    }

    private:
    std::shared_ptr<std::vector<string>> data;
    void check(size_type i,string str){
        if (i > data->size()){
            throw std::out_of_range(str);
        }
    }
};
