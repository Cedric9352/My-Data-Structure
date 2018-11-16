#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include <map>
#include <sstream>
#include "query_result.h"

/**
 * class TextQuery
 */
class TextQuery
{
public:
    /*type define*/
    typedef std::vector<std::string>::size_type line_no;
    /*constructor*/
    TextQuery(std::istream &is);
    /*public method*/
    QueryResult query(const std::string &word) const;
private:
    /*private method*/
    void trim(std::string&);
    /*private field*/
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
/**
 * constructor of class TextQuery
 */
TextQuery::TextQuery(std::istream &is): file(new std::vector<std::string>)
{
    std::string text;
    while(std::getline(is, text)) {
        file->push_back(text);
        int n = file->size()-1;
        std::istringstream line(text);
        std::string word;
        while(line >> word) {
            trim(word);
            auto &lines = wm[word];
            if(!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}
/**
 * member method of class TextQuery
 */
QueryResult TextQuery::query(const std::string &word) const
{
    std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(word);
    if(loc == wm.end()) {
        return QueryResult(word, nodata, file);
    } else {
        return QueryResult(word, loc->second, file);
    }
}
void TextQuery::trim(std::string &s)
{
    auto beg = s.begin(), end = s.end()-1;
    while(!std::isalpha(*beg)) { ++beg; }
    while(!std::isalpha(*end)) { --end; }
    s = s.substr(beg-s.begin(), end-beg+1);
}
#endif // TEXT_QUERY_H
