#pragma once
#include <memory>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::set;
using std::map;
using std::vector;
using std::stringstream;

class wy_queryResult;
class wy_textQuery{
    public:
        typedef std::shared_ptr<std::vector<std::string>> sp_file_Tp;
        typedef shared_ptr<map<string,set<int>>> sp_Qmap_Tp;

        //constructor.
        wy_textQuery() = default;
        wy_textQuery(std::istream & in);

        wy_queryResult query(std::string& word)const;

    private:
        //smart pointer to a vector storing a file.
        sp_file_Tp sp_fileData = nullptr;

        //smart pointer to storing the result of queries.
        sp_Qmap_Tp sp_queryMap = nullptr;
};
