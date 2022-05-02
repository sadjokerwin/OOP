#include <iostream>
#include "Date.h"
void enterDate()
{
    int day, month, year;
    while (!isValidDate(day, month, year))
    {
        cin >> day >> month >> year;
    }
    Date(day, month, year);
}
bool isValidDate(int day, int month, int year)
{
    if (month > 0 && month < 13)
    {
        if (month == 1 && month == 3 && month == 5 && month == 7 && month == 8 && month == 10 && month == 12)
        {
            return day <= 31;
        }
        else if (month == 2)
        {
            if (isLeapYear(year))
                return day <= 29;
            else
                return day <= 28;
        }
        else
            return day <= 30;
    }
}
bool isLeapYear(int year)
{
    if (year <= 1916)
        return year % 4 == 0;
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
Date::Date()
{
    mDay = 1;
    mMonth = 1;
    mYear = 1;
}
Date::Date(size_t day, size_t month, size_t year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}
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
    this->mYear = year;
    if (isLeapYear(year))
        monthDays[1] = 29;
    else
        monthDays[1] = 28;
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
int operator-(const Date &lhs, const Date &rhs)
{
    int lhsDayNum, rhsDayNum, diff;
    for (int i = 0; i < lhs.mMonth - 1; i++)
    {
        lhsDayNum += lhs.monthDays[i];
    }
    lhsDayNum += lhs.mDay;
    for (int i = 0; i < rhs.mMonth - 1; i++)
    {
        rhsDayNum += rhs.monthDays[i];
    }
    rhsDayNum += rhs.mDay;
    diff = rhsDayNum - lhsDayNum;
    return diff;
    // if (isValidDate(mDay, mMonth, mYear))
    // {
    //     return *this;
    // }
    // else
    // {
    //     if ((mMonth - 1) >= 1)
    //     {
    //         mMonth -= 1;
    //         if (mMonth == 1 && mMonth == 3 && mMonth == 5 && mMonth == 7 && mMonth == 8 && mMonth == 10 && mMonth == 12)
    //         {
    //             mDay = 31;
    //         }
    //     }
    // }
}
// Date Date::operator+=(const Date &other)
// {
//     mDay += other.mDay;
//     for (int i = 1; i <= other.mDay; i++)
//     {
//         if (isValidDate(mDay, mMonth, mYear))
//         {
//             return *this;
//         }
//         else
//         {
//             if ((mMonth + 1) <= 12)
//             {
//                 mMonth += 1;
//                 mDay = 1;
//             }
//             else
//             {
//                 mYear += 1;
//                 mMonth = 1;
//                 mDay = 1;
//             }
//         }
//     }
// }
bool Date::operator==(const Date &rhs)
{
    return (mDay == rhs.mDay) && (mMonth == rhs.mMonth) && (mYear == rhs.mYear);
}
bool Date::operator>(const Date &rhs)
{
    if ((*this - rhs) > 0)
        return true;
    else
        return false;
}
std::ostream &operator<<(std::ostream &out, const Date &date)
{
    return out << date.mDay << date.mMonth << date.mYear;
}
std::istream &operator>>(std::istream &in, Date &date)
{
    return in >> date.mDay >> date.mMonth >> date.mYear;
}
