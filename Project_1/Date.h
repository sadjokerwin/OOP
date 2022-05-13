#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;
void enterDate();
bool isValidDate(int, int, int);
bool isLeapYear(int);
class Date
{
private:
    size_t mDay;
    size_t mMonth;
    size_t mYear;
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    Date();
    Date(size_t, size_t, size_t);
    Date &operator=(const Date &);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    size_t getDay() const;
    size_t getMonth() const;
    size_t getYear() const;
    void nextDay();
    int weekDay() const;
    bool operator==(const Date &) const;
    bool operator>(const Date &) const;
    bool operator>=(const Date &) const;
    friend int operator-(const Date &, const Date &);
    friend std::ostream &operator<<(std::ostream &, const Date &);
    friend std::istream &operator>>(std::istream &, Date &);
};

#endif