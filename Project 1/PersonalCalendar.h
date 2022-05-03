#ifndef __PERSONALCALENDAR_H
#define __PERSONALCALENDAR_H
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Time.h"
#include "Meeting.h"
class personalCalendar
{
private:
    Meeting **mCalendar;
    size_t mMeetingCount;
    size_t mCapacity;
    void resize();
    void sort();
    void print();

public:
    personalCalendar();
    personalCalendar(size_t, size_t);
    Meeting **getmCalendar() const;
    void addMeeting(const Meeting &);
    void cancelMeeting(const char *, const char *, const Date&, const Time&, const Time&);
    void daySchedule(const Date &) const;
    void changeMeeting();
};
#endif