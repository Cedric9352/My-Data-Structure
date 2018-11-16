#ifndef WORD_QUERY_H
#define WORD_QUERY_H
#include "query.h"

/**
 * class WordQuery
 */
class WordQuery : public Query_base
{
    friend class Query;
    WordQuery(const std::string &s): query_word(s) { }
    // please notice that this points to a constant object, hence query is a constant string
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    std::string rep() const { return query_word; }
    /*private field*/
    std::string query_word;
};
/**
 * Query constructor to WordQuery
 */
inline Query::Query(const std::string &s): q(new WordQuery(s)) { }
#endif // WORD_QUERY_H
