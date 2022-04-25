#include <iostream>
#include "Date.h"
void Date::setDay(int day)
{
    mDay = day;
}
void Date::setMonth(int month)
{
    mMonth = month;
}
void Date::setYear(int year)
{
    mYear = year;
}
size_t Date::getDay() const
{
    return mDay;
}
size_t Date::getMonth() const
{
    return mMonth;
}
size_t Date::getYear() const
{
    return mYear;
}