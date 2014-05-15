#include "date.h"

Date::Date()
{
    day = 1;
    month = 1;
    year = 2013;
}

Date::Date(int day, int mon, int year)
{
    setDay(day);
    setMonth(mon);
    setYear(year);
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::setDay(int day)
{
    this->day = day;
}

void Date::setMonth(int mon)
{
    this->month = mon;
}

void Date::setYear(int year)
{
    this->year = year;
}
