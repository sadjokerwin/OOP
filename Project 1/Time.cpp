#include <iostream>
#include "Time.h"
void enterTime()
{
    int hours, mins, secs;
    while (!isValidTime(hours, mins, secs))
    {
        cin >> hours >> mins >> secs;
    }
    Time(hours, mins, secs);
}
bool isValidTime(int hours, int mins, int secs)
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
bool Time::operator<(const Time &other)
{
    return mTimeInSecs < other.mTimeInSecs;
}
bool Time::operator==(const Time &other)
{
    return mTimeInSecs == other.mTimeInSecs;
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
    return out << other.mHours << ":" << other.mMins << ":" << other.mSecs;
}
