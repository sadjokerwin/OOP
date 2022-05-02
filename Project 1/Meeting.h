#ifndef __MEETING_H
#define __MEETING_H
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Time.h"
class Meeting
{
    private:
    char *mName;
    char *mMeetingInfo;
    Date mDate;
    Time mBegin;
    Time mEnd;
    void copyFrom(const Meeting &);
    void free();

public:
    Meeting();
    Meeting(const Meeting &);
    Meeting &operator=(const Meeting &);
    void setName(const char *);
    void setMeetingInfo(const char *);
    void setDate(const Date &);
    void setBeginTime(const Time &);
    void setEndTime(const Time &);
    const char *getName() const;
    const char* getMeetingInfo() const;
    Date getDate() const;
    Time getBeginTime() const;
    Time getEndTime() const;
    ~Meeting();
};
void enterMeeting(Meeting &);
void writeInFile(const Meeting &);
#endif