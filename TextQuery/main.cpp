#include <fstream>
#include <iostream>
#include "binary_query.h"
#include "not_query.h"
#include "word_query.h"

using namespace std;

int main()
{
    std::ifstream ifs("./test_file.txt");
    TextQuery t(ifs);
    Query q = (Query("fiery") & Query("bird")) | Query("wind");
    q.eval(t);
    cout << q.eval(t) << endl;
    return 0;
}
