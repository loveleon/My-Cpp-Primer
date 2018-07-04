#include "ex13_42_TextQuery.h"
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs):input(new StrVec){
    std::size_t lineNo = 0;
    if(ifs){
        std::string line;
        for(std::string line;getline(ifs,line);++lineNo){
           input->push_back(line);
            std::istringstream text(line);
            for(std::string temp,word;text >> temp;word.clear()){
                std::remove_copy_if(temp.begin(),temp.end(),std::back_inserter(word),ispunct);
                auto &it = result[word];
                if(!it)
                    it.reset(new std::set<size_t>);
                else{
                    it->insert(lineNo);
                }
            }
            }
        }
}
QueryResult TextQuery::query(const std::string& word) const{
    static std::shared_ptr<std::set<size_t>> nodata (new std::set<size_t>);
    auto found = result.find(word);
    if(found == result.end()){
        return QueryResult(word,nodata,input);
    }else{
        return QueryResult(word,found->second,input);
    }
}

std::ostream& print(std::ostream &out, const QueryResult &qr){
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i+1 << ") " << qr.input->at(i) << std::endl;
    return out;
}
