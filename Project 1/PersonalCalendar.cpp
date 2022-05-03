#include <iostream>
#include <fstream>
#include "PersonalCalendar.h"
void personalCalendar::resize()
{
    Meeting **tempCalendar = new Meeting *[mCapacity * 2];
    for (int i = 0; i < mMeetingCount; i++)
    {
        tempCalendar[i] = mCalendar[i];
    }
    mCapacity *= 2;
    delete[] mCalendar;
    mCalendar = tempCalendar;
}
void personalCalendar::sort()
{
    for (int x = 0; x < mMeetingCount; x++)
    {
        for (int y = x + 1; y < mMeetingCount; y++)
        {
            if (mCalendar[x] > mCalendar[y])
                swap(mCalendar[x], mCalendar[y]);
        }
    }
}
personalCalendar::personalCalendar()
{
    // mCalendar = nullptr;
    // mCalendar = nullptr;
    mMeetingCount = 0;
    mCapacity = 4;
}
personalCalendar::personalCalendar(size_t meetingCount, size_t capacity)
{
    mMeetingCount = meetingCount;
    mCapacity = capacity;
}
Meeting **personalCalendar::getmCalendar() const
{
    return mCalendar;
}
void personalCalendar::addMeeting(const Meeting& meet)
{
    if ((mMeetingCount + 1) > (mCapacity * 3) / 4)
    {
        resize();
    }
    // Meeting m1(enterMeeting());
    // printMeeting(m1);
    //---
    mCalendar[mMeetingCount] = new Meeting(meet);
    mMeetingCount++;
    cout << mMeetingCount;

    writeInFile(*mCalendar[mMeetingCount]);
    // sort();
}
void personalCalendar::cancelMeeting(const char *name, const char *meetInfo, const Date &date, const Time &begin, const Time &end)
{
    Meeting temp(name, meetInfo, date, begin, end);
    for (int i = 0; i < mMeetingCount; i++)
    {
        if (*mCalendar[i] == temp)
        {
            // calendar[i] == nullptr;
        }
    }
}