#include "PersonalCalendar.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void personalCalendar::resize()
{
    Meeting **tempCalendar = new Meeting *[mCapacity * 2];
    for (int i = 0; i < mMeetingCount; i++)
    {
        tempCalendar[i] = mCalendar[i];
        // printMeeting(*(tempCalendar[i]));
    }
    // if (mCapacity == 0)
    //     mCapacity = 1;
    // else
    //     mCapacity *= 2;
    delete[] mCalendar;
    mCapacity *= 2;
    mCalendar = tempCalendar;
    // cout << mCapacity;
}
void personalCalendar::sort()
{
    int counter = 0;
    for (int x = 0; x < mMeetingCount; x++)
    {
        for (int y = x + 1; y < mMeetingCount; y++)
        {
            cout << "For index [" << x << "] and index [" << y << "]";
            if (mCalendar[y] == nullptr)
                continue;
            if (mCalendar[x] == nullptr)
            {
                cout << "nullptr swap" << '\n';
                mCalendar[x] = new Meeting(*mCalendar[y]);
                mCalendar[y] = nullptr;
                counter++;
                // mCalendar[y] = nullptr;
            }
            else if (*mCalendar[x] > *mCalendar[y])
            {
                cout << "swap" << '\n';
                swap(mCalendar[y], mCalendar[x]);
            }
        }
    }
    mMeetingCount -= counter;
}
void personalCalendar::erase()
{
    for (size_t i = 0; i < mCapacity; i++)
    {
        delete mCalendar[i];
    }

    delete[] mCalendar;
}
size_t personalCalendar::findElement(const Meeting &other) const
{
    for (int i = 0; i < mMeetingCount; i++)
    {
        if ((*mCalendar[i]).getDate() == other.getDate() && (*mCalendar[i]).getBeginTime() == other.getBeginTime() && (*mCalendar[i]).getEndTime() == other.getEndTime())
        {
            if (strcmp((*mCalendar[i]).getName(), other.getName()) == 0 && strcmp((*mCalendar[i]).getMeetingInfo(), other.getMeetingInfo()) == 0)
            {
                return i;
            }
        }
    }
    return -1;
}
personalCalendar::personalCalendar()
{
    // mCalendar = (Meeting **)NULL;
    mCapacity = 16;
    mMeetingCount = 0;
    mCalendar = new Meeting *[mCapacity];
}
personalCalendar::personalCalendar(size_t meetingCount, size_t capacity)
{
    // mCalendar = (Meeting **)NULL;
    mMeetingCount = meetingCount;
    mCapacity = capacity;
    mCalendar = new Meeting *[mCapacity];
}
size_t personalCalendar::getMeetingCount() const
{
    return mMeetingCount;
}
size_t personalCalendar::getCapacity() const
{
    return mCapacity;
}
void personalCalendar::setMeetingCount(size_t meetCount)
{
    mMeetingCount = meetCount;
}
void personalCalendar::setCapacity(size_t capacity)
{
    mCapacity = capacity;
}
Meeting **personalCalendar::getmCalendar() const
{
    return mCalendar;
}
void personalCalendar::addMeeting(const Meeting &meet)
{
    if ((mMeetingCount + 1) > (mCapacity * 3) / 4)
    {
        resize();
    }
    if (!isTimeSlotTaken(meet))
    {
        mCalendar[mMeetingCount] = new Meeting(meet);
        mMeetingCount++;
        cout << "MeetingCount" << mMeetingCount << '\n';
    }
    else
    {
        cout << "There is already a meeting in this time slot! ";
    }
    if (mMeetingCount > 1)
    {
        // cout << "probva swap";
        sort();
    }
}
bool personalCalendar::isTimeSlotTaken(const Meeting &other) const
{
    for (int i = 0; i < mMeetingCount; i++)
    {
        if ((*mCalendar[i]).getDate() == other.getDate())
        {
            if ((other.getBeginTime() > (*mCalendar[i]).getBeginTime() || other.getBeginTime() == (*mCalendar[i]).getBeginTime()) && ((*mCalendar[i]).getEndTime() > other.getBeginTime() || (*mCalendar[i]).getEndTime() == other.getBeginTime()))
            {
                cout << "true1" << endl;
                return true;
            }
            if ((other.getEndTime() > (*mCalendar[i]).getBeginTime() || other.getEndTime() == (*mCalendar[i]).getBeginTime()) && ((*mCalendar[i]).getEndTime() > other.getEndTime() || (*mCalendar[i]).getEndTime() == other.getEndTime()))
            {
                cout << "true2" << endl;
                return true;
            }
        }
        else
        {
            cout << "false";
        }
    }
    return false;
}
void personalCalendar::addMeeting()
{
    cout << "Enter the details of the meeting you want to add: " << endl;
    if ((mMeetingCount + 1) > (mCapacity * 3) / 4)
    {
        cout << "resize";
        resize();
    }
    Meeting *temp = new Meeting(enterMeeting());
    if (!isTimeSlotTaken(*temp))
    {
        mCalendar[mMeetingCount] = new Meeting(*temp);
        mMeetingCount++;
        cout << "MeetingCount" << mMeetingCount << '\n';
    }
    else
    {
        cout << "There is already a meeting in this time slot! ";
    }
    if (mMeetingCount > 1)
        sort();
    // delete temp;
}
void personalCalendar::cancelMeeting()
{
    cout << "Enter the details of the meeting you want to cancel: " << endl;
    Meeting *temp = new Meeting(enterMeeting());
    for (int i = 0; i < mMeetingCount; i++)
    {
        if (*mCalendar[i] == *temp)
        {
            mCalendar[i] = nullptr;
            sort();
            cout << endl
                 << mMeetingCount;
        }
    }
    delete temp;
}
void personalCalendar::daySchedule(const Date &date) const
{
    for (int i = 0; i < mMeetingCount; i++)
    {
        if (mCalendar[i]->getDate() == date)
        {
            printMeeting(*getmCalendar()[i]);
        }
    }
}
void personalCalendar::changeMeeting()
{
    cout << "Enter the details of the meeting you want to change: " << endl;
    Meeting tempMeet(enterMeeting());
    int index = findElement(tempMeet);
    cout << "Enter the information you would like to change: " << endl;
    cout << "The options are: " << endl
         << "Meeting name, Meeting info, Meeting date, Start time, End time"<<endl;
    char *temp;
    cin.getline(temp, MAX_SIZE);
    if (strcmp("Meeting name", temp) == 0)
    { 
        cout << "Enter the new name: " << endl;
        char *name;
        cin.getline(name, MAX_SIZE);
        (*mCalendar[index]).setName(name);
    }
    if (strcmp("Meeting info", temp) == 0)
    {
        char *meetinginfo;
        cout << "Enter the new meeting info: " << endl;
        cin.getline(meetinginfo, MAX_SIZE);
        (*mCalendar[index]).setMeetingInfo(meetinginfo);
    }
    if (strcmp("Meeting date", temp) == 0)
    {
        
        int day, month, year;
        cout << "Enter the new date: " << endl;
        while (!isValidDate(day, month, year))
        {
            cout << "Day: ";
            cin >> day;
            cout << "Month: ";
            cin >> month;
            cout << "Year: ";
            cin >> year;
        }
        Date d(day, month, year);
        (*mCalendar[index]).setDate(d);
    }
    if (strcmp("Start time", temp) == 0)
    {
        size_t hours, minutes, seconds;
        cout << "Enter the new start time: " << endl;
        while (!isValidTime(hours, minutes, seconds))
        {
            cout << "Hours: ";
            cin >> hours;
            cout << "Minutes: ";
            cin >> minutes;
            cout << "Seconds: ";
            cin >> seconds;
        }
        Time t(hours, minutes, seconds);
        (*mCalendar[index]).setBeginTime(t);
    }
    if (strcmp("End time", temp) == 0)
    {
        size_t hours, minutes, seconds;
        cout << "Enter the new end time: " << endl;
        while (!isValidTime(hours, minutes, seconds))
        {
            cout << "Hours: ";
            cin >> hours;
            cout << "Minutes: ";
            cin >> minutes;
            cout << "Seconds: ";
            cin >> seconds;
        }
        Time t(hours, minutes, seconds);
        (*mCalendar[index]).setEndTime(t);
    }
}
personalCalendar::~personalCalendar()
{
    erase();
}