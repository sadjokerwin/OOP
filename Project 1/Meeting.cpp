#include <iostream>
#include <fstream>
#include <cstring>
#include "Meeting.h"
#define MAX_SIZE 1024
#pragma warning(disable : 4996)
using namespace std;

void printMeeting(const Meeting &other)
{
    if (&other != nullptr)
    {
        cout << '\n'
             << "Meeting:" << '\n'
             << "Name: " << other.getName() << '\n'
             << "Information: " << other.getMeetingInfo() << '\n'
             << "Date: " << other.getDate() << '\n'
             << "Begins at: " << other.getBeginTime() << '\n'
             << "Ends at: " << other.getEndTime();
    }
    else
        cout << "nulapointer" << endl;
}
const Meeting enterMeeting()
{
    Meeting meet;
    char buffer[MAX_SIZE];
    cout << "Enter the meeting name: " << '\n';
    cin.getline(buffer, MAX_SIZE, '\n');
    meet.setName(buffer);

    cout << "Enter the meeting's info(Maximum length - 1024 characters):" << '\n';
    // cin.ignore();
    cin.getline(buffer, MAX_SIZE);
    meet.setMeetingInfo(buffer);

    cout << "Enter the meeting's date: " << '\n';
    Date date;
    cin >> date;
    meet.setDate(date);

    cout << "Enter the meeting's start time: " << '\n';
    Time start;
    cin >> start;
    meet.setBeginTime(start);

    cout << "Enter the meeting's end time: " << '\n';
    Time end;
    cin >> end;
    meet.setEndTime(end);
    cin.ignore();
    return meet;
}
void writeInFile(const Meeting &meet)
{
    ofstream file("Personal_Calendar.txt", ios::app);
    file.write(meet.getName(), strlen(meet.getName()));
    file << "|";
    file.write(meet.getMeetingInfo(), strlen(meet.getMeetingInfo()));
    file << "|";
    file << meet.getDate().getDay() << "." << meet.getDate().getMonth() << "." << meet.getDate().getYear();
    file << "|";
    file << meet.getBeginTime().getHours() << ":" << meet.getBeginTime().getMins() << ":" << meet.getBeginTime().getSeconds();
    file << "|";
    file << meet.getEndTime().getHours() << ":" << meet.getEndTime().getMins() << ":" << meet.getEndTime().getSeconds() << "\n";
    file.close();
}
void Meeting::copyFrom(const Meeting &other)
{
    mName = new char[strlen(other.mName) + 1];
    strcpy(mName, other.mName);
    mMeetingInfo = new char[strlen(other.mMeetingInfo) + 1];
    strcpy(mMeetingInfo, other.mMeetingInfo);
    mDate = other.mDate;
    mBegin = other.mBegin;
    mEnd = other.mEnd;
}
void Meeting::free()
{
    delete mName;
    delete mMeetingInfo;
}
Meeting::Meeting()
{
    // mName = (char*)NULL;
    mName = new char[1];
    mName[0] = '\0';
    // mMeetingInfo = (char *)NULL;
    mMeetingInfo = new char[1];
    mMeetingInfo[0] = '\0';
    Date mDate(0, 0, 0);
    Time mBegin(0, 0, 0);
    Time mEnd(0, 0, 0);
}
Meeting::Meeting(const char *name, const char *meetinginfo, const Date &date, const Time &begin, const Time &end)
{
    setName(name);
    setMeetingInfo(meetinginfo);
    mDate = date;
    mBegin = begin;
    mEnd = end;
}
Meeting::Meeting(const Meeting &other)
{
    // cout << "copyconstr";
    copyFrom(other);
}
Meeting &Meeting::operator=(const Meeting &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
void Meeting::setName(const char *name)
{
    mName = new char[strlen(name)];
    strcpy(mName, name);
}
void Meeting::setMeetingInfo(const char *meetingInfo)
{
    mMeetingInfo = new char[strlen(meetingInfo)];
    strcpy(mMeetingInfo, meetingInfo);
}
void Meeting::setDate(const Date &date)
{
    mDate = date;
}
void Meeting::setBeginTime(const Time &timeBeg)
{
    if (!(timeBeg > getEndTime()))
        mBegin = timeBeg;
    else
    {
        mBegin.setHours(mEnd.getHours());
        mBegin.setMin(mEnd.getMins());
        mBegin.setSeconds(mEnd.getSeconds());
    }
    
}
void Meeting::setEndTime(const Time &timeEnd)
{
    if (timeEnd > mBegin)
        mEnd = timeEnd;
    else
    {
        mEnd.setHours(mBegin.getHours());
        mEnd.setMin(mBegin.getMins());
        mEnd.setSeconds(mBegin.getSeconds());
    }
}
const char *Meeting::getName() const
{
    return mName;
}
const char *Meeting::getMeetingInfo() const
{
    return mMeetingInfo;
}
const Date Meeting::getDate() const
{
    return mDate;
}
const Time Meeting::getBeginTime() const
{
    return mBegin;
}
const Time Meeting::getEndTime() const
{
    return mEnd;
}
bool Meeting::operator==(const Meeting &other) const
{
    return (strcmp(mName, other.mName) == 0) && (strcmp(mMeetingInfo, other.mMeetingInfo) == 0) && (mDate == other.mDate) && (mBegin == other.mBegin) && (mEnd == other.mEnd);
}
bool Meeting::operator>(const Meeting &other) const
{
    if (mDate > other.mDate)
        return 1;
    if (mDate == other.mDate)
    {
        if (mBegin > other.mBegin)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
Meeting::Meeting(Meeting &&other)
{
    mName = other.mName;
    mMeetingInfo = other.mMeetingInfo;
    mDate = other.mDate;
    mBegin = other.mBegin;
    mEnd = other.mEnd;
    other.mName = nullptr;
    other.mMeetingInfo = nullptr;
    std::cout << "move constr" << std::endl;
}
Meeting::~Meeting()
{
    free();
}