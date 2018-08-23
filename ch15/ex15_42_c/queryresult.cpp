/***************************************************************************
 *  @file       queryresult.cpp
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark     using class StrBlob
 ***************************************************************************/


#include "queryresult.h"
#include <cassert>

/**
 * @brief   print the result to the output stream specified.
 * @note    class QueryResult's friend
 */
std::ostream
&print(std::ostream &os, const QueryResult &qr)
{
    os <<"The result of your query "<< qr.sought <<" is: \n";
    for (const auto &index: *qr.lines)
        os << "\t(line " << index + 1 << ")"
           << *(qr.file->begin() + index) << "\n";
    return os;
}

std::ostream& print(std::ostream& os, const QueryResult &qr, size_t head, size_t tail)
{
    if(head > tail)
    {
		os << "illegal range!\n";
        return os;
    }

    os << "the result of your query:" << qr.sought << " is:\n";
    for(auto& index : *qr.lines)
    {
        if(index+1>=head && index+1<=tail)
            os << "\t(line " << index+1 << ")"
            << *(qr.file->begin() + index) << "\n";
    }
    return os;
}
