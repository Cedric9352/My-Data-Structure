#include <iostream>
#include "easy_date.h"

using namespace std;

int main()
{
    easy_date date(2017, 1, 1);
    cout << date - 365 << endl;
    return 0;
}
