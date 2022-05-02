#include <iostream>
#include <fstream>
#include "PersonalCalendar.h"
void personalCalendar::resize(size_t newMeetingCount)
{
    Meeting **tempCalendar = new Meeting *[newMeetingCount];
    int minCount;
    if (meetingCount <= newMeetingCount)
        minCount = meetingCount;
    else
        minCount = newMeetingCount;

    for (int i = 0; i < minCount; i++)
    {
        tempCalendar[i] = calendar[i];
    }
    meetingCount = newMeetingCount;
    delete[] calendar;
    calendar = tempCalendar;
}
void personalCalendar::addMeeting()
{
    resize(meetingCount + 1);
    calendar[meetingCount - 1] = new Meeting(enterMeeting());
    meetingCount++;
}
void personalCalendar::cancelMeeting(const char *name, const char *meetInfo, const Date &date, const Time &begin, const Time &end)
{
    Meeting temp(name, meetInfo, date, begin, end);
    for (int i = 0; i < meetingCount; i++)
    {
        if (*calendar[i] == temp)
        {
            // calendar[i] == nullptr;
        }
    }
}