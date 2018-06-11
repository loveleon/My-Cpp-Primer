#ifndef _EX12_27_H__
#define _EX12_27_H__
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>

#include "ex12_22.h"

using std::istream;
using std::map;
using std::set;
using std::string;
using std::vector;
using std::shared_ptr;
using std::ostream;
using std::endl;
using std::ifstream;
using std::cout;
using std::cin;
using std::istringstream;
using std::pair;

class QueryResult;
ostream & print(ostream &out,QueryResult &result);
//ostream & print(ostream &out,const QueryResult &result);

class TextQuery{
    friend class QueryResult;
    public:
    typedef vector<string>::size_type VSIZE_TYPE;
    public:
        TextQuery(istream &infile);
        QueryResult query(const string &word);
    private:
        map<string,shared_ptr<set<StrBlob::size_type>>> result;
        StrBlob file;
};

class QueryResult{
    friend ostream & print(ostream &out,const QueryResult &result);
    friend ostream & print(ostream &out,QueryResult &result);
    public:
    typedef std::set<StrBlob::size_type>::iterator Iter;
    public:
        QueryResult(const string word_,shared_ptr<set<StrBlob::size_type>> sset_,StrBlob &input_);
        Iter begin();
        Iter end();
        shared_ptr<StrBlob> get_file();
    private:
        shared_ptr<set<StrBlob::size_type>> nos;
        string word;
        StrBlob file;
};

shared_ptr<StrBlob> QueryResult::get_file(){
    return std::make_shared<StrBlob>(file);
}

QueryResult::Iter QueryResult::begin(){
    auto it = nos->begin();
    return it;
}

QueryResult::Iter QueryResult::end(){
    auto it = nos->end();
    return it;
}

QueryResult::QueryResult(const string word_,shared_ptr<set<StrBlob::size_type>> sset_,StrBlob &input_){
    nos = sset_;
    word = word_;
    file = input_;
}

ostream &print(ostream &out, QueryResult &rst){
    out << rst.word << " ocur "<< rst.nos->size() << ( rst.nos->size() > 1 ?" times":" time") << endl;
    for(auto pos = rst.begin(); pos != rst.end(); pos++){
    //for(auto pos : *rst.nos){
        //StrBlobPtr sbp(rst.file,pos);
        StrBlobPtr sbp(*rst.get_file(),*pos);
        out << "    (line " << *pos+1 << " )";
        out << sbp.deref() << endl;
    }
    return out;
}

TextQuery::TextQuery(istream &infile):file(StrBlob()){
    VSIZE_TYPE i=0;
    if(infile){
        for(string line;getline(infile,line);++i){
            file.push_back(line);

            istringstream is(line);
            for(string text,word;is >> text;word.clear()){
                std::remove_copy_if(text.begin(),text.end(),std::back_inserter(word),ispunct);
                auto &sset = result[word];
                if(!sset)
                    sset.reset(new set<VSIZE_TYPE>());
                sset->insert(i);
        }
    }
    cout << "result map:" << endl;
    for(auto mmap : result){
        cout << mmap.first << " and lines:";
        for(auto it : *(mmap.second)){
            cout << it << " ";
        }
        cout << endl;
    }
}
}

QueryResult TextQuery::query(const string &word){
    static shared_ptr<set<VSIZE_TYPE>> nodata = std::make_shared<set<StrBlob::size_type>>();
   auto found =  result.find(word);
   if(found == result.end()){
        return  QueryResult(word,nodata,file);
   }else{
       return QueryResult(word,found->second,file);
   }
}
#endif
