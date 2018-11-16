#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H
#include <algorithm>
#include "query.h"

/**
 * class BinaryQuery
 */
class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
        lhs(l), rhs(r), opSym(s) { }
    std::string rep() const { return "(" + lhs.rep() + " "
                                         + opSym + " "
                                         + rhs.rep() +")"; }
    /*protected field*/
    Query lhs, rhs;
    std::string opSym;
};
/**
 * class AndQuery
 */
class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery&) const;
};
/**
 * Query constructor to AndQuery
 */
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
/**
 * eval of AndQuery
 */
QueryResult AndQuery::eval(const TextQuery &text) const
{
    // actually invoke eval of WordQuery
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(left.begin(), left.end(),
                          right.begin(), right.end(),
                          // inserter, add element before second iterator
                          std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}
/**
 * class OrQuery
 */
class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|") { }
    QueryResult eval(const TextQuery&) const;
};
/**
 * Query constructor to OrQuery
 */
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
/**
 * eval of OrQuery
 */
QueryResult OrQuery::eval(const TextQuery &text) const
{
    // actually invoke eval of WordQuery
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}
#endif // BINARY_QUERY_H
