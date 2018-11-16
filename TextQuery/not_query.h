#ifndef NOT_QUERY_H
#define NOT_QUERY_H
#include "query.h"

/**
 * class NotQuery
 */
class NotQuery : public Query_base
{
    friend Query operator~(const Query&);
    NotQuery(const Query &q): query(q) { }
    std::string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    /*private field*/
    Query query;
};
/**
 * Query constructor to NotQuery
 */
inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
/**
 * eval of NotQuery
 */
QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query.eval(text);
    auto begin = result.begin(), end = result.end();
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto sz = result.get_file()->size();
    for(size_t n = 0; n != sz; ++n) {
        // check whether the line containing word exists(nodata) or
        // line does not equal to n
        if(begin == end || *begin != n) {
            ret_lines->insert(n);
        } else if(begin != end) {
            ++begin;
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}
#endif // NOT_QUERY_H
