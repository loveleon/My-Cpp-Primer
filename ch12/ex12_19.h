#ifndef _EX12_09_H__
#define _EX12_09_H__
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::weak_ptr;

class StrBlobPtr;
class StrBlob{
    friend class StrBlobPtr;
    public:
        typedef vector<string>::size_type size_type;
    public:
        StrBlob():data(std::make_shared<vector<string>>()){}
        StrBlob(std::initializer_list<string> il):data(std::make_shared<vector<string>>(il)){}
        size_type size()const {
            return data->size();
        }
        StrBlobPtr begin();
        StrBlobPtr end();
        bool empty(){return data->empty();}
        void push_back(const string &str){data->push_back(str);};
        void pop_back(){
            check(0,"empty of vector data.");
            data->pop_back();
        };

        string& front(){
            check(0,"empty front.");
            return data->front();};
        const string& front() const{
            check(0,"empty front.");
            return data->front();
        };
        string& back(){
            check(0,"back on empty.");
            return data->back();
        };
        const string& back()const{
            check(0,"back on empty.");
            return data->back();
        };
    private:
        std::shared_ptr<vector<string>> data;
        void check(size_type sz,string str)const;
};

class StrBlobPtr{
    public:
        string & deref()const{
            auto p = check(curr,"reach the end.");
            return p->at(curr);
        }

        StrBlobPtr& incr(){
            check(curr,"increment past the end.");
            curr++;
            return *this;
        }

        StrBlobPtr():curr(0){}
        StrBlobPtr(StrBlob &sb, size_t sz=0):wptr(sb.data),curr(sz){}
        bool operator!=(const StrBlobPtr &p){return p.curr != curr;}
    private:
            shared_ptr<vector<string>> check(size_t sz,const string &str)const;
            weak_ptr<vector<string>> wptr;
            size_t curr;
};

StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
    auto ret = StrBlobPtr(*this,data->size());
    return ret;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string &str)const{
    auto ret = wptr.lock();
    if(!ret){
        throw std::runtime_error(str);
    }else{
        if(sz >= ret->size()){
            throw std::runtime_error(str);
        }
        else{
            return ret;
        }
    }
}
#endif
