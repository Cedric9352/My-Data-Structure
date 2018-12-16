#ifndef EASY_DATE_H
#define EASY_DATE_H
#include <iostream>
#include <stdexcept>
#include <string>

/**
 * class easy date
 */
class easy_date
{
public:
    typedef std::size_t date_type;
    friend std::ostream& operator<<(std::ostream &, const easy_date&);
    friend easy_date operator+(const easy_date&, date_type);
    friend easy_date operator-(const easy_date&, date_type);
    easy_date(date_type, date_type, date_type);
    easy_date(const easy_date&) = default;
    easy_date(easy_date&&) = default;
    easy_date& operator=(const easy_date&) = default;
    easy_date& operator=(easy_date&&) = default;
    ~easy_date() = default;
    static bool is_leap_year(date_type year) { return (year % 100 == 0) ? (year % 400 == 0) : (year % 4 == 0); }
private:
    static const date_type common_days[12];
    static const std::string common_name[12];
    date_type day;
    date_type month;
    date_type year;
};
/**
 * static variable
 */
const easy_date::date_type easy_date::common_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::string easy_date::common_name[12] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
/**
 * constructor
 */
easy_date::easy_date(date_type year = 1900, date_type month = 1, date_type day = 1): day(day), month(month), year(year)
{
    if(month > 12) { throw std::range_error("wrong month"); }
    if(month != 2) { if(day > common_days[month]) { throw std::range_error("wrong day for given month"); } }
    else {
        if(easy_date::is_leap_year(year)) { if(day > common_days[month]) { throw std::range_error("wrong day for given month"); } }
        else { if(day > common_days[month]+1) { throw std::range_error("wrong day for given month"); } }
    }
}
/**
 * operator add/minus
 */
easy_date operator+(const easy_date &date, easy_date::date_type days)
{
    easy_date::date_type year = date.year;
    easy_date::date_type month = date.month, max_days = (month != 2) ? easy_date::common_days[month-1]
                                                                     : (easy_date::is_leap_year(year) ? easy_date::common_days[month-1]+1 : easy_date::common_days[month-1]);
    easy_date::date_type day = date.day+days;
    while(day > max_days) {
        day -= max_days;
        ++month;
        year = month == 13 ? year+1 : year;
        month = month == 13 ? 1 : month;
        max_days = (month != 2) ? easy_date::common_days[month-1]
                                : (easy_date::is_leap_year(year) ? easy_date::common_days[month-1]+1 : easy_date::common_days[month-1]);
    }
    return easy_date(year, month, day);
}
easy_date operator-(const easy_date &date, easy_date::date_type days)
{
    easy_date::date_type year = date.year;
    easy_date::date_type month = date.month;
    easy_date::date_type day = date.day;
    while(day <= days) {
        --month;
        year = month == 0 ? year-1 : year;
        month = month == 0 ? 12 : month;
        day += (month != 2) ? easy_date::common_days[month-1]
                            : (easy_date::is_leap_year(year) ? easy_date::common_days[month-1]+1 : easy_date::common_days[month-1]);
    }
    day -= days;
    return easy_date(year, month, day);
}
std::ostream& operator<<(std::ostream &os, const easy_date &date)
{
    os << date.year << ", "
       << easy_date::common_name[date.month-1]  << ", "
       << date.day;
    return os;
}
#endif // EASY_DATE_H
