#include "wy_textquery.h"
#include "wy_queryresult.h"
#include "debugdelete.h"

wy_textQuery::wy_textQuery(std::istream& in):
    sp_fileData(new vector<string>(),DebugDelete()),
    sp_queryMap(new map<string,set<int>>,DebugDelete())
{
    //custom delter may not use with std::make_shared,as it has internal deleter which may not be inplaced.
    //As a result,keyword new is the only option to use with DebugDeleter.
    string line;
    while(getline(in,line))
    {
        sp_fileData->push_back(line);
    }

}

wy_queryResult wy_textQuery::query(std::string &qword)const
{
    std::size_t counter = 0;
    for(std::size_t i=0; i<sp_fileData->size();++i)
    {
        stringstream ss((*sp_fileData)[i]);
        string word;
        while(ss>>word)
        {
            if(!qword.compare(word))
            {
                ++counter;
                (*sp_queryMap)[word].insert(counter);
            }
        }
    }

    wy_queryResult result(counter,qword,sp_fileData,sp_queryMap);
    return result;
}
