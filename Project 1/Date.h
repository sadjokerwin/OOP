#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;
class Date
{
private:
    size_t mDay;
    size_t mMonth;
    size_t mYear;

public:
    Date();
    Date(size_t, size_t, size_t)
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    size_t getDay() const;
    size_t getMonth() const;
    size_t getYear() const;
};
#endif
#kur