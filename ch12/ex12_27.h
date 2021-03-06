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
ostream & print(ostream &out,const QueryResult &result);

class TextQuery{
    friend class QueryResult;
    public:
    typedef vector<string>::size_type VSIZE_TYPE;
    public:
        TextQuery(istream &infile);
        QueryResult query(const string &word);
    private:
        map<string,shared_ptr<set<VSIZE_TYPE>>> result;
        shared_ptr<vector<string>> input;
};

class QueryResult{
    friend ostream & print(ostream &out,const QueryResult &result);
    public:
        QueryResult(const string word_,shared_ptr<set<TextQuery::VSIZE_TYPE>> sset_,shared_ptr<vector<string>> input_);
    private:
        shared_ptr<set<TextQuery::VSIZE_TYPE>> rst;
        string word;
        shared_ptr<vector<string>> input;
};

QueryResult::QueryResult(const string word_,shared_ptr<set<TextQuery::VSIZE_TYPE>> sset_, shared_ptr<vector<string>> input_){
    rst = sset_;
    word = word_;
    input = input_;
}

ostream &print(ostream &out, const QueryResult &rst){
    auto member = rst.rst;
    auto times = member->size();
    out << rst.word << " ocur "<< times << (times > 1 ?" times":" time") << endl;
    for(auto sit=member->cbegin();sit != member->cend();sit++){
        auto vec = rst.input;
        out << "    (line " << *sit << " )";
        out << vec->at(*sit) << endl;
    }
    return out;
}

TextQuery::TextQuery(istream &infile):input(std::make_shared<vector<string>>()){
    VSIZE_TYPE i=0;
    if(infile){
        for(string line;getline(infile,line);++i){
            input->push_back(line);

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
    static shared_ptr<set<VSIZE_TYPE>> nodata = std::make_shared<set<VSIZE_TYPE>>();
   auto found =  result.find(word);
   if(found == result.end()){
        return  QueryResult(word,nodata,input);
   }else{
       return QueryResult(word,found->second,input);
   }
}
#endif
