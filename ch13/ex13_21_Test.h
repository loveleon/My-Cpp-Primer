#ifndef MY_CLASS
#define MY_CLASS

#include<iostream>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<memory>

class QueryResult;
std::ostream& print(std::ostream&, const QueryResult&);

class TextQuery {
public:
    //typedef
    using line_no = std::vector<std::string>::size_type;
    //constructor
    TextQuery(std::ifstream&);
    //Query function
    QueryResult query(const std::string&) const;
    TextQuery(const TextQuery&) = delete;
    TextQuery& operator=(const TextQuery&) = delete;
private:
    //data members
    std::shared_ptr<std::vector<std::string>> in_file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> word_occr;
};

//TextQuery constructor
TextQuery::TextQuery(std::ifstream& input) : in_file(new std::vector<std::string>) {
    for (std::string text; getline(input, text); in_file->push_back(text)) {
        int cur_line_no = in_file->size() + 1;
        std::string word;
        for (std::istringstream line(text); line >> word; ) {
            auto &line_nums = word_occr[word];
            if (!line_nums)
                line_nums.reset(new std::set<TextQuery::line_no>);
            line_nums->insert(cur_line_no);
        }
    }
}

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    //constructor
    QueryResult(std::string s,
        std::shared_ptr<std::vector<std::string>> f,
        std::shared_ptr<std::set<TextQuery::line_no>> l)
        : sought(s), file(f), lines(l) { }
    QueryResult(const QueryResult&) = delete;
    QueryResult& operator=(const QueryResult&) = delete;



    QueryResult(QueryResult &&) noexcept = default; //!! here!!



    //member functions
    std::set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
    std::set<TextQuery::line_no>::iterator end() { return lines->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
    //data members
    std::string sought;             //word sought by this query
    std::shared_ptr<std::vector<std::string>> file;         //file we are searching in
    std::shared_ptr<std::set<TextQuery::line_no>> lines;    //lines sought is found on
};

QueryResult TextQuery::query(const std::string& s) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto found = word_occr.find(s);
    if (found == word_occr.end())
        return QueryResult(s, in_file, nodata);
    else
        return QueryResult(s, in_file, found->second);
}

std::ostream& print(std::ostream& out, const QueryResult& qr) {
    out << qr.sought << " : " << qr.lines->size() << std::endl;
    return out;
}

#endif
