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

class TextQuery;
class QueryResult{
    friend ostream & print(ostream &out,const QueryResult &result);
    public:
        QueryResult(shared_ptr<vector<string>> sp ,const string key,map<string,set<int>>::iterator it);
        //QueryResult(shared_ptr<vector<string>> sp ,const string key,pair<string,set<int>> wordPair);
        //QueryResult(TextQuery &text,const string &key,pair<string,set<int>> wordPair);

    private:
        map<string,set<int>> mWordNums;
        string word;
        shared_ptr<vector<string>> spVecLineContent;

};

ostream & print(ostream &out,const QueryResult &result);

QueryResult::QueryResult(shared_ptr<vector<string>> sp, const string key,map<string,set<int>>::iterator it){
    spVecLineContent = sp;
//    mWordNums.insert(wordPair);
//    mWordNums.insert(std::make_pair<string,set<int>>(it->first,it->second));
    mWordNums[it->first] = it->second;
    word = key;
    cout <<"use count " << sp.use_count() << endl;
}

ostream &print(ostream &out, const QueryResult &rst){
    auto member = rst.mWordNums;
    auto it = member.find(rst.word);
    auto times = it->second.size();
    auto sset = it->second;
    out << it->first << " ocur " << it->second.size() << (times > 1 ?" times":" time") << endl;
    for(auto sit=sset.cbegin();sit != sset.cend();sit++){
        out << "(line " << *sit << " )" << rst.spVecLineContent->at(*sit) << endl;
    }
    return out;
}

class TextQuery{
    friend class QueryResult;
    public:
        TextQuery(istream &infile);
        QueryResult query(const string &word);
    private:
        map<string,set<int>> mWordLineNum;
       map<string,set<int>>::iterator Find(const string &word){
            //return *mWordLineNum.find(word);
            auto it = mWordLineNum.find(word);
            return it;
        }
        shared_ptr<vector<string>> spVecFileContent;
};

TextQuery::TextQuery(istream &infile){
    spVecFileContent = std::make_shared<vector<string>>();
    cout << "TextQuery " << endl;
    int i=0;
    if(infile){
        string line;
        while(getline(infile,line)){
            istringstream is(line);
            string word;
            ++i;
            spVecFileContent->push_back(line);
            while(is >> word){
                mWordLineNum[word].insert(i);
            }
        }
    }
//*
    cout << "mWordLineNum content:" << endl;
    for_each(mWordLineNum.cbegin(),mWordLineNum.cend(),[](const pair<string,set<int>> p){cout << p.first ;
            for(const auto item : p.second){
            cout << item << " ";
            }
            cout << endl;
            });

    cout << endl << endl;
    cout << "spVecFileContent :" << endl;
    for(const auto it :*spVecFileContent){
        cout << it << endl;
    }
    //*/
}

QueryResult TextQuery::query(const string &word){
    auto p = Find(word);
    cout << "find the keyword " << p->first << endl;
//    auto qr = std::pair<string,set<int>>(p);
    //QueryResult QR(spVecFileContent,word,qr);
    QueryResult QR(spVecFileContent,word,p);
    return QR;
}
#endif
