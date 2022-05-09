#ifndef __MEETING_H
#define __MEETING_H
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Time.h"
using namespace std;
class Meeting
{
    private:
    char* mName;
    char* mMeetingInfo;
    Date mDate;
    Time mBegin;
    Time mEnd;
    void copyFrom(const Meeting &);
    void free(); 

public:
    Meeting();
    Meeting(const char *, const char *, const Date &, const Time &, const Time &);
    Meeting(const Meeting&);
    Meeting &operator=(const Meeting &);
    void setName(const char *);
    void setMeetingInfo(const char *);
    void setDate(const Date &);
    void setBeginTime(const Time &);
    void setEndTime(const Time &);
    const char *getName() const;
    const char* getMeetingInfo() const;
    const Date getDate() const;
    const Time getBeginTime() const;
    const Time getEndTime() const;
    bool operator==(const Meeting &) const;
    bool operator>(const Meeting &) const;
    Meeting(Meeting &&);
    ~Meeting();
};
void printMeeting(const Meeting &);
void writeInFile(const Meeting &);
const Meeting enterMeeting();
#endif