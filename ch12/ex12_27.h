#ifndef _EX12_27_H__
#define _EX12_27_H__
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <memory>

using std::istream;
using std::map;
using std::set;
using std::string;
using std::vector;
using std::shared_ptr;
using std::ostream;

class TextQuery;
class QueryResult{
    friend ostream & print(ostream &out,const QueryResult &result);
    public:
        QueryResult(TextQuery &text,const string &key);

//    private:
    public:
        map<string,set<int>> mWordNums;
        string &word;
        shared_ptr<vector<string>> spVecLineContent;

};

ostream &print(ostream &out,const QueryResult &rst){
    for(const auto &item : rst.mWordNums){
        if(item.first == rst.word){

        }
    }

    auto member = rst.mWordNums;
    auto it = member.find(rst.word);
    out << it->first ;//<< endl;
    return out;
}

class TextQuery{
    friend class QueryResult;
    public:
        TextQuery(istream &infile);
        QueryResult query(const string &word);
    private:
        map<string,set<int>> mWordLineNum;
        shared_ptr<vector<string>> spVecFileContent;
};
#endif
