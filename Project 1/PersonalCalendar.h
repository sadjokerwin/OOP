#ifndef __PERSONALCALENDAR_H
#define __PERSONALCALENDAR_H
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Time.h"
#include "Meeting.h"
using namespace std;
class personalCalendar
{
private:
    Meeting** mCalendar;
    size_t mMeetingCount;
    size_t mCapacity;
    void resize();
    void sort();
    void print();
    void erase();
    size_t findElement(const Meeting &) const;

public:
    
    personalCalendar();
    personalCalendar(size_t, size_t);
    size_t getMeetingCount() const;
    size_t getCapacity() const;
    void setMeetingCount(size_t);
    void setCapacity(size_t);
    Meeting **getmCalendar() const;
    void addMeeting();
    void addMeeting(const Meeting &);
    void cancelMeeting();
    void daySchedule(const Date &) const;
    void changeMeeting();
    bool isTimeSlotTaken(const Meeting &) const;
    ~personalCalendar();
};

#endif