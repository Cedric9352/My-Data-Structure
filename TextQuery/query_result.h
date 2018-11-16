#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include <iostream>
#include <memory>
#include <string>
#include <set>
#include <vector>

/**
 * class QueryResult
 */
class QueryResult
{
/*friend*/
friend std::ostream& operator<<(std::ostream &os, const QueryResult &qr);
public:
    /*type define*/
    typedef std::vector<std::string>::size_type line_no;
    /*constructor*/
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) { }
    const std::shared_ptr<std::vector<std::string>>& get_file() const { return file; }
    std::set<line_no>::iterator begin() { return (*lines).begin(); }
    std::set<line_no>::iterator end() { return (*lines).end(); }
private:
    /*private field*/
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
/**
 * output operator
 */
std::ostream& operator<<(std::ostream &os, const QueryResult &qr)
{
    os << "Executing Query for: " << qr.sought << "\n"
       << qr.sought << " occurs " << qr.lines->size() << " "
       << "times " << std::endl;
       for(auto num : *qr.lines) {
           os << "\t(line " << num+1 << ") " << (*(qr.file))[num] << std::endl;
       }
       return os;
}
#endif // QUERY_RESULT_H
