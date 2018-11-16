#ifndef QUERY_H
#define QUERY_H
#include "query_base.h"

/**
 * class Query
 */
class Query
{
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }
private:
    /*private constructor*/
    Query(std::shared_ptr<Query_base> query): q(query) { }
    /*private field*/
    std::shared_ptr<Query_base> q;
};
/**
 * output operator
 */
std::ostream& operator<<(std::ostream &os, const Query &query) { return os << query.rep(); }
#endif // QUERY_H
