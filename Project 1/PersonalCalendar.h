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
    Meeting **mCalendar;
    size_t mMeetingCount;
    size_t mCapacity;
    void resize();
    void sort();
    void print();
    void erase();
    size_t findElement(const Meeting &) const;
    char *turnIntoFileName(const Date &) const;
    Date turnIntoDate(const char *);
    Time turnIntoTime(const char *);
    bool isNewBeginTimeValid(size_t, const Date &, size_t) const;
    bool isNewEndTimeValid(size_t, const Date &, size_t) const;
    bool isNewDataValid(size_t , size_t , size_t , size_t) const;

public:
    personalCalendar();
    personalCalendar(size_t, size_t);
    void loadFromFile(std::ifstream &);
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
    void searchForMeetings() const;
    bool isTimeSlotTaken(const Meeting &) const;
    void meetingByDayOfWeek(Date, Date) const;
    void findFreeTimeSlot(const Date &, const Date &, const Time&, const Time&, const Time&) const;
    void saveToFile(std::ofstream &) const;
    ~personalCalendar();
};
void runProgram();

#endif