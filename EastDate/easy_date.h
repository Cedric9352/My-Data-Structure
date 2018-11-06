#ifndef EASY_DATE_H
#define EASY_DATE_H
#include <iostream>
#include <stdexcept>
#include <string>

/**
 * class easy date
 */
class EasyDate
{
friend std::ostream& operator<<(std::ostream &, const EasyDate &);
public:
    EasyDate(unsigned months, unsigned days);
    EasyDate(const EasyDate&) = default;
    EasyDate& operator=(const EasyDate&) = default;
    ~EasyDate() = default;
    EasyDate& operator+(unsigned n);
    EasyDate& operator-(unsigned n);
private:
    static const unsigned common_days[12];
    static const std::string common_name[12];
    unsigned days;
    unsigned months;
};
/**
 * static variable
 */
const unsigned EasyDate::common_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::string EasyDate::common_name[12] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
/**
 * constructor
 */
EasyDate::EasyDate(unsigned months = 1, unsigned days = 1): days(days), months(months)
{
    if(days > 31 || months > 12) {
        throw std::runtime_error("wrong days or months");
    } else if(common_days[months-1] < days) {
        throw std::runtime_error("exceed maximum days");
    }
}
/**
 * operator
 */
EasyDate& EasyDate::operator+(unsigned n)
{
    unsigned months = this->months, max_days = this->common_days[months-1];
    unsigned days = this->days+n;
    while(days > max_days) {
        days -= max_days;
        ++months;
        months = months == 13 ? 1 : months;
        max_days = this->common_days[months-1];
    }
    this->months = months;
    this->days = days;
    return *this;
}
EasyDate& EasyDate::operator-(unsigned n)
{
    unsigned months = this->months;
    unsigned days = this->days;
    if(days > n) {
        days -= n;
    } else {
        while(days <= n) {
            days += this->common_days[months-1];
            --months;
            months = months == 0 ? 12 : months;
        }
        days -= n;
    }
    this->months = months;
    this->days = days;
    return *this;
}
std::ostream& operator<<(std::ostream &os, const EasyDate &ed)
{
    os << ed.common_name[ed.months-1] << ", " << ed.days;
    return os;
}
#endif // EASY_DATE_H
