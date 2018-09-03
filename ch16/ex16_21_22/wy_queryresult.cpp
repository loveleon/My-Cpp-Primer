#include "wy_queryresult.h"

inline wy_queryResult::wy_queryResult(const wy_queryResult& qr):
    occurrence(qr.getCounter()),queryWord(qr.getQueryWord()),
    sp_file(qr.getSp_file()),sp_Qmap(qr.getSp_Qmap())
{
}

wy_queryResult::wy_queryResult(std::size_t s,const std::string& word,
        const wy_textQuery::sp_file_Tp& _sp_file,const wy_textQuery::sp_Qmap_Tp& _sp_qmap):
    occurrence(s),queryWord(word),sp_file(_sp_file),sp_Qmap(_sp_qmap)
{
}

//a none member function.
std::ostream& print(std::ostream& out,const wy_queryResult &qr)
{
    std::string queryWord = qr.getQueryWord();
    out << "The word ["
        <<queryWord << "] occurs "
        <<qr.getCounter() << " times:\n";

    auto sp_f = qr.getSp_file();
    auto sp_m = qr.getSp_Qmap();

    for(const auto& index:(*sp_m)[queryWord])
    {
        out << "\nLine " << index << " )" << (*sp_f)[index] << "\n\n";
    }

    return out;
}
