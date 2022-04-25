#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;
class Date{
    private:
    size_t mDay;
    size_t mMonth;
    size_t mYear;
    public:
        void Date::setHours(int hours)
        {
            mHours = hours;
        }
        void Date::setMin(int min)
        {
            mMins = min;
        }
        void Date::setSeconds(int seconds)
        {
            mSecs = seconds;
        }
        size_t Date::getHours() const
        {
            return mHours;
        }
        size_t Date::getMins() const
        {
            return mMins;
        }
        size_t Date::getSeconds() const
        {
            return mSecs;
        }
};
#endif