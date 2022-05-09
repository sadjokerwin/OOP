#include <iostream>
#include "Time.h"
using namespace std;
void enterTime()
{
    int hours=0, mins=0, secs=0;
    while (!isValidTime(hours, mins, secs))
    {
        cin >> hours >> mins >> secs;
    }
    Time(hours, mins, secs);
}
bool isValidTime(size_t hours, size_t mins, size_t secs)
{
    if (hours < 0 || hours >= 24 || mins < 0 || mins >= 60 || secs < 0 || secs >= 60)
    {
        return false;
    }
    return true;
}
void Time::turnToSec()
{
    mTimeInSecs = mHours * 3600 + mMins * 60 + mSecs;
}
void Time::convertToNormal()
{
    int copyTimeInSecs = mTimeInSecs;
    mHours = copyTimeInSecs / 3600;
    copyTimeInSecs %= 3600;
    mMins = copyTimeInSecs / 60;
    copyTimeInSecs %= 60;
    mSecs = copyTimeInSecs;
}
Time::Time()
{
    setHours(0);
    setMin(0);
    setSeconds(0);
}
Time::Time(size_t hours, size_t mins, size_t secs)
{
    setHours(hours);
    setMin(mins);
    setSeconds(secs);
    turnToSec();
}
Time &Time::operator=(const Time &other)
{
    if (isValidTime(other.mHours, other.mMins, other.mSecs))
    {
        mHours = other.mHours;
        mMins = other.mMins;
        mSecs = other.mSecs;
        turnToSec();
    }
    return *this;
}
void Time::setHours(int hours)
{
    mHours = hours;
}
void Time::setMin(int min)
{
    mMins = min;
}
void Time::setSeconds(int seconds)
{
    mSecs = seconds;
}
size_t Time::getHours() const
{
    return mHours;
}
size_t Time::getMins() const
{
    return mMins;
}
size_t Time::getSeconds() const
{
    return mSecs;
}
size_t Time::getTimeInSecs() const
{
    return mTimeInSecs;
}
bool Time::operator>(const Time &other) const
{
    if (mHours > other.mHours)
        return 1;
    if (mHours == other.mHours)
    {
        if (mMins > other.mMins)
            return 1;
        if (mMins == other.mMins)
        {
            if (mSecs > other.mSecs)
                return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}
bool Time::operator==(const Time &other) const {
    return mHours == other.mHours && mMins == other.mMins && mSecs == other.mSecs;
}
Time operator-(const Time &lhs, const Time &rhs)
{
    Time diff;
    diff.mTimeInSecs = lhs.mTimeInSecs;
    diff.mTimeInSecs -= rhs.mTimeInSecs;
    diff.convertToNormal();
    return diff;
}
std::ostream &operator<<(std::ostream &out, const Time &other)
{
    if (other.mHours <= 9)
        out << "0" << other.mHours << ":";
    else
        out << other.mHours << ":";
    if (other.mMins <= 9)
        out << "0" << other.mMins << ":";
    else
        out << other.mMins << ":";
    if (other.mSecs <= 9)
        out << "0" << other.mSecs;
    else
        out << other.mSecs;
    return out;
}
std::istream &operator>>(std::istream &in, Time &other)
{
    return in >> other.mHours >> other.mMins >> other.mSecs;
}
