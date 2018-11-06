#include <iostream>
#include "easy_date.h"

using namespace std;

int main()
{
    EasyDate ed(12, 31);
    cout << ed + 10 << endl;
    return 0;
}
