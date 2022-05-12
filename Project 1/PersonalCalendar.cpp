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
    }
    delete[] mCalendar;
    mCapacity *= 2;
    mCalendar = tempCalendar;
}
void personalCalendar::sort()
{
    int counter = 0;
    for (int x = 0; x < mMeetingCount - 1; x++)
    {
        for (int y = x + 1; y < mMeetingCount; y++)
        {
            // cout << "For index [" << x << "] and index [" << y << "]";
            // if (mCalendar[y] == nullptr)
            //     continue;
            if (mCalendar[y] == nullptr)
                continue;
            if (mCalendar[x] == nullptr)
            {
                // cout << "nullptr swap" << '\n';
                mCalendar[x] = new Meeting(*mCalendar[y]);
                mCalendar[y] = nullptr;
                counter++;
            }
            else if (*mCalendar[x] > *mCalendar[y])
            {
                // cout << "swap" << '\n';
                swap(mCalendar[y], mCalendar[x]);
            }
        }
    }
    // mMeetingCount -= counter;
}
void personalCalendar::erase()
{
    for (size_t i = 0; i < mMeetingCount; i++)
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
char *personalCalendar::turnIntoFileName(const Date &periodBegin) const
{
    char *fileName = new char[20];
    int yearCopy = periodBegin.getYear();
    int monthCopy = periodBegin.getMonth();
    int dateCopy = periodBegin.getDay();
    fileName[0] = 's';
    fileName[1] = 't';
    fileName[2] = 'a';
    fileName[3] = 't';
    fileName[4] = 's';
    fileName[5] = '-';
    int counter = 0;
    for (int i = 6; i < 10; i++)
    {
        fileName[9 - counter] = 48 + yearCopy % 10;
        yearCopy /= 10;
        counter++;
    }
    fileName[10] = '-';
    fileName[12] = 48 + monthCopy % 10;
    monthCopy /= 10;
    fileName[11] = 48 + monthCopy % 10;
    fileName[13] = '-';
    fileName[15] = 48 + dateCopy % 10;
    dateCopy /= 10;
    fileName[14] = 48 + dateCopy % 10;
    fileName[16] = '.';
    strcat(fileName, "txt");
    return fileName;
}
Date personalCalendar::turnIntoDate(const char *dateString)
{
    size_t day, month, year;
    day = ((int)dateString[0] - 48) * 10 + ((int)dateString[1] - 48);
    month = ((int)dateString[3] - 48) * 10 + ((int)dateString[4] - 48);
    year = ((int)dateString[6] - 48) * 1000 + ((int)dateString[7] - 48) * 100 + ((int)dateString[8] - 48) * 10 + ((int)dateString[9] - 48);
    Date *d = new Date(day, month, year);
    return *d;
}
Time personalCalendar::turnIntoTime(const char *timeString)
{
    size_t hours, mins, secs;
    hours = ((int)timeString[0] - 48) * 10 + ((int)timeString[1] - 48);
    mins = ((int)timeString[3] - 48) * 10 + ((int)timeString[4] - 48);
    secs = ((int)timeString[6] - 48) * 10 + ((int)timeString[7] - 48);
    Time *t = new Time(hours, mins, secs);
    return *t;
}
bool personalCalendar::isNewBeginTimeValid(size_t timeInSecs, const Date &date, size_t index) const
{
    int hours, mins, secs;
    hours = timeInSecs / 3600;
    timeInSecs %= 3600;
    mins = timeInSecs / 60;
    timeInSecs %= 60;
    secs = timeInSecs;
    Time temp(hours, mins, secs);
    for (int i = 0; i < index; i++)
    {
        if (date == mCalendar[i]->getDate())
        {
            if (!(temp > mCalendar[i]->getEndTime()))
                return false;
        }
    }
    return true;
}
bool personalCalendar::isNewEndTimeValid(size_t timeInSecs, const Date &date, size_t index) const
{
    int hours, mins, secs;
    hours = timeInSecs / 3600;
    timeInSecs %= 3600;
    mins = timeInSecs / 60;
    timeInSecs %= 60;
    secs = timeInSecs;
    Time temp(hours, mins, secs);
    for (int i = index+1; i < mMeetingCount; i++)
    {
        if (date == mCalendar[i]->getDate())
        {
            if (temp > mCalendar[i]->getBeginTime())
                return false;
        }
    }
    return true;
}
bool personalCalendar::isNewDataValid(size_t day, size_t month, size_t year, size_t index) const
{
    Date date(day, month, year);
    for (int i = 0; i < index; i++)
    {
        if(date==mCalendar[i]->getDate())
        {
            if ((mCalendar[index]->getBeginTime() > (*mCalendar[i]).getBeginTime() || mCalendar[index]->getBeginTime() == (*mCalendar[i]).getBeginTime()) && ((*mCalendar[i]).getEndTime() > mCalendar[index]->getBeginTime() || (*mCalendar[i]).getEndTime() == mCalendar[index]->getBeginTime()))
            {
                // cout << "true1" << endl;
                return true;
            }
            if ((mCalendar[index]->getEndTime() > (*mCalendar[i]).getBeginTime() || mCalendar[index]->getEndTime() == (*mCalendar[i]).getBeginTime()) && ((*mCalendar[i]).getEndTime() > mCalendar[index]->getEndTime() || (*mCalendar[i]).getEndTime() == mCalendar[index]->getEndTime()))
            {
                // cout << "true2" << endl;
                return true;
            }
        }
    }
    for (int i = index+1; i < mMeetingCount; i++)
    {
        if (date == mCalendar[i]->getDate())
        {
            if ((mCalendar[index]->getBeginTime() > (*mCalendar[i]).getBeginTime() || mCalendar[index]->getBeginTime() == (*mCalendar[i]).getBeginTime()) && ((*mCalendar[i]).getEndTime() > mCalendar[index]->getBeginTime() || (*mCalendar[i]).getEndTime() == mCalendar[index]->getBeginTime()))
            {
                // cout << "true1" << endl;
                return true;
            }
            if ((mCalendar[index]->getEndTime() > (*mCalendar[i]).getBeginTime() || mCalendar[index]->getEndTime() == (*mCalendar[i]).getBeginTime()) && ((*mCalendar[i]).getEndTime() > mCalendar[index]->getEndTime() || (*mCalendar[i]).getEndTime() == mCalendar[index]->getEndTime()))
            {
                // cout << "true2" << endl;
                return true;
            }
        }
    }
    return false;
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
/*void personalCalendar::loadFromFile(std::ifstream &fromFile)
{
    while (!fromFile.eof())
    {
        Meeting *m;
        m = new Meeting;
        char *buffer = new char[MAX_SIZE];
        fromFile.getline(buffer, MAX_SIZE, '|');
        m->setName(buffer);
        fromFile.getline(buffer, MAX_SIZE, '|');
        m->setMeetingInfo(buffer);
        char *date = new char[11];
        fromFile.getline(date, 10, '|');
        m->setDate(turnIntoDate(date));
        char *time = new char[9];
        fromFile.getline(date, 8, '|');
        m->setBeginTime(turnIntoTime(time));
        fromFile.getline(date, 8, '|');
        m->setEndTime(turnIntoTime(time));
        addMeeting(*m);
        fromFile.get();
        delete date;
        delete time;
        delete buffer;
    }
}*/
void personalCalendar::loadFromFile(std::ifstream &fromFile)
{
    while (!fromFile.eof())
    {
        Meeting m;
        char buffer[MAX_SIZE];
        // name
        // fromFile.get();
        fromFile.getline(buffer, MAX_SIZE, '|');
        // cout << buffer << endl;
        m.setName(buffer);
        // meetinginfo
        fromFile.getline(buffer, MAX_SIZE, '|');
        // cout << buffer << endl;
        m.setMeetingInfo(buffer);
        // date
        char *date = new char[11];
        fromFile.getline(date, 11, '|');
        // cout << date;
        m.setDate(turnIntoDate(date));
        // begintime
        char *time = new char[9];
        fromFile.getline(time, 9, '|');
        // cout << time << endl;
        m.setBeginTime(turnIntoTime(time));
        // endtime
        fromFile.getline(time, 9, '\n');
        m.setEndTime(turnIntoTime(time));
        // cout << m;
        addMeeting(m);
        // cout << fromFile.get();
        delete date;
        delete time;
        // delete buffer;
        // delete m;
        // fromFile.get();
    }
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
        // cout << "resize";
        resize();
    }
    if (!isTimeSlotTaken(meet))
    {
        mCalendar[mMeetingCount] = new Meeting(meet);
        mMeetingCount++;
        // cout << "MeetingCount" << mMeetingCount << '\n';
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
                // cout << "true1" << endl;
                return true;
            }
            if ((other.getEndTime() > (*mCalendar[i]).getBeginTime() || other.getEndTime() == (*mCalendar[i]).getBeginTime()) && ((*mCalendar[i]).getEndTime() > other.getEndTime() || (*mCalendar[i]).getEndTime() == other.getEndTime()))
            {
                // cout << "true2" << endl;
                return true;
            }
        }
        else
        {
            // cout << "false";
        }
    }
    return false;
}
void personalCalendar::addMeeting()
{
    cout << "Enter the details of the meeting you want to add: " << endl;
    if ((mMeetingCount + 1) > mCapacity)
    {
        cout << "resize" << endl;
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
    delete temp;
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

            // cout << endl
            //      << mMeetingCount;
        }
    }
    sort();
    mMeetingCount--;
    delete temp;
}
void personalCalendar::daySchedule(const Date &date) const
{
    cout << "Daily schedule for " << date << endl;
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
    // printMeeting(tempMeet);
    int index = findElement(tempMeet);
    cout << "Enter the information you would like to change: " << endl;
    cout << "The options are: " << endl
         << "Meeting name, Meeting info, Meeting date, Start time, End time" << endl;
    char *temp = new char[MAX_SIZE];
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
        cout << "Enter the new meeting info: " << endl;
        char *meetinginfo = new char[MAX_SIZE];
        cin.getline(meetinginfo, MAX_SIZE);
        // cout << meetinginfo;
        (*mCalendar[index]).setMeetingInfo(meetinginfo);
    }
    if (strcmp("Meeting date", temp) == 0)
    {
        int day = 60, month = 0, year = 0;
        cout << "Enter the new date: " << endl;
        while (!isValidDate(day, month, year)||isNewDataValid(day, month, year, index))
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
        size_t hours = 24, minutes = 0, seconds = 0;
        int newTimeInSecs = hours * 3600 + minutes * 60 + seconds;
        cout << "Enter the new start time: " << endl;
        while (!isValidTime(hours, minutes, seconds)||(newTimeInSecs>mCalendar[index]->getEndTime().getTimeInSecs())||!(isNewBeginTimeValid(newTimeInSecs, mCalendar[index]->getDate(), index)))
        {
            cout << "Hours: ";
            cin >> hours;
            cout << "Minutes: ";
            cin >> minutes;
            cout << "Seconds: ";
            cin >> seconds;
            newTimeInSecs = hours * 3600 + minutes * 60 + seconds;
        }
        Time t(hours, minutes, seconds);
        (*mCalendar[index]).setBeginTime(t);
    }
    if (strcmp("End time", temp) == 0)
    {
        size_t hours=24, minutes=0, seconds=0;
        int newTimeInSecs = hours * 3600 + minutes * 60 + seconds;
        cout << "Enter the new end time: " << endl;
        while (!isValidTime(hours, minutes, seconds) || (newTimeInSecs < mCalendar[index]->getBeginTime().getTimeInSecs()) || !(isNewEndTimeValid(newTimeInSecs, mCalendar[index]->getDate(), index)))
        {
            cout << "Hours: ";
            cin >> hours;
            cout << "Minutes: ";
            cin >> minutes;
            cout << "Seconds: ";
            cin >> seconds;
            newTimeInSecs = hours * 3600 + minutes * 60 + seconds;
        }
        Time t(hours, minutes, seconds);
        (*mCalendar[index]).setEndTime(t);
    }
    delete temp;
}
void personalCalendar::searchForMeetings() const
{
    cout << "Enter the information you want the meeting to contain: " << endl;
    cout << "The options are: " << endl
         << "Meeting name, Meeting info" << endl;
    char *temp1 = new char[MAX_SIZE];
    cin.getline(temp1, MAX_SIZE);
    if (strcmp("Meeting name", temp1) == 0)
    {
        cout << "Enter the name: " << endl;
        char *name;
        cin.getline(name, MAX_SIZE);
        for (int i = 0; i < mMeetingCount; i++)
        {
            if (strcmp((*mCalendar[i]).getName(), name) == 0)
                printMeeting((*mCalendar[i]));
        }
    }
    if (strcmp("Meeting info", temp1) == 0)
    {
        char *meetinginfo;
        cout << "Enter the meeting info: " << endl;
        cin.getline(meetinginfo, MAX_SIZE);
        for (int i = 0; i < mMeetingCount; i++)
        {
            if (strcmp((*mCalendar[i]).getMeetingInfo(), meetinginfo) == 0)
                printMeeting((*mCalendar[i]));
        }
    }
    delete temp1;
}
void personalCalendar::meetingByDayOfWeek(Date periodBegin, Date periodEnd) const
{

    char *fileName = turnIntoFileName(periodBegin);
    ofstream file(fileName, ios::trunc);
    int *workLoad = new int[7];
    for (int x = 0; x < 7; x++)
    {
        workLoad[x] = 0;
    }
    int dayOfWeek = periodBegin.weekDay();
    int decrementCounter = 0;
    periodEnd.nextDay();
    while (!(periodBegin == periodEnd))
    {
        for (int i = 0 + decrementCounter; i < mMeetingCount; i++)
        {
            if (mCalendar[i]->getDate() == periodBegin)
            {
                workLoad[dayOfWeek]++;
                decrementCounter++;
            }
        }
        periodBegin.nextDay();
        dayOfWeek++;
        dayOfWeek %= 7;
    }
    int indexForBusiestDay = 0;
    file << "Days of the week sorted from busiest to the least busy: " << endl;
    for (int y = 0; y < 7; y++)
    {
        indexForBusiestDay = 0;
        for (int x = 0; x < 7; x++)
        {
            if (workLoad[indexForBusiestDay] < workLoad[x + 1])
                indexForBusiestDay = x + 1;
        }
        switch (indexForBusiestDay)
        {
        case 0:
            file << "Sunday: " << workLoad[0] << endl;
            break;
        case 1:
            file << "Monday: " << workLoad[1] << endl;
            break;
        case 2:
            file << "Tuesday: " << workLoad[2] << endl;
            break;
        case 3:
            file << "Wednesday: " << workLoad[3] << endl;
            break;
        case 4:
            file << "Thursday: " << workLoad[4] << endl;
            break;
        case 5:
            file << "Friday: " << workLoad[5] << endl;
            break;
        case 6:
            file << "Saturday: " << workLoad[6] << endl;
            break;
        }
        workLoad[indexForBusiestDay] = -1;
    }
    file.close();
    delete workLoad;
}
void personalCalendar::findFreeTimeSlot(const Date &periodBegin, const Date &periodEnd, const Time &duration, const Time &timePeriodBegin, const Time &timePeriodEnd) const
{

    Date periodBeginCopy = periodBegin;
    Date periodEndCopy = periodEnd;
    bool isThereTimeSlot = false;
    // cout << isThereTimeSlot;
    periodEndCopy.nextDay();
    int decrementCounter = 0;
    while (!(periodBeginCopy == periodEndCopy))
    {
        for (int i = 0 + decrementCounter; i < mMeetingCount - 1; i++)
        {

            if (mCalendar[i]->getDate() >= periodBegin && !(mCalendar[i]->getDate() > periodEnd) && (mCalendar[i + 1]->getDate() >= periodBegin && !(mCalendar[i + 1]->getDate() > periodEnd)))
            {
                if (mCalendar[i]->getDate() == mCalendar[i + 1]->getDate())
                {
                    if (mCalendar[i]->getBeginTime() >= timePeriodBegin && !(mCalendar[i]->getBeginTime() > timePeriodEnd) && (mCalendar[i + 1]->getEndTime() >= timePeriodBegin) && !(mCalendar[i + 1]->getEndTime() > timePeriodEnd))
                    {
                        if (((*mCalendar[i + 1] - *mCalendar[i]) >= duration))
                        {
                            cout << "There is a time slot between ";
                            printMeeting(*mCalendar[i]);
                            cout << endl
                                 << "and ";
                            printMeeting(*mCalendar[i + 1]);
                            cout << endl;
                            cout << "##########################" << endl;
                            cout << "##########################" << endl;
                            if (!isThereTimeSlot)
                                isThereTimeSlot = true;
                            // decrementCounter++;
                            // cout << isThereTimeSlot;
                        }
                    }
                }
            }
            decrementCounter++;
        }
        periodBeginCopy.nextDay();
    }

    if (!isThereTimeSlot)
        cout << "There are no suitable time slots for a meeting in the selected hours! ";
}
void personalCalendar::saveToFile(std::ofstream &toFile) const
{
    for (int i = 0; i < mMeetingCount - 1; i++)
    {
        toFile << *(mCalendar[i]) << endl;
    }
    toFile << *(mCalendar[mMeetingCount - 1]);
}
personalCalendar::~personalCalendar()
{
    erase();
}
