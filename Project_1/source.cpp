#include <iostream>
#include <fstream>
#include <cstring>
#include "Date.h"
#include "Time.h"
#include "Meeting.h"
#include "PersonalCalendar.h"
#include "Date.cpp"
#include "Time.cpp"
#include "Meeting.cpp"
#include "PersonalCalendar.cpp"
using namespace std;
void runProgram()
{
    cout << "Would you like to load information from the calendar? (Yes/No)" << endl;
    char temp[4];
    cin.getline(temp, 4, '\n');
    personalCalendar p;
    if (strcmp(temp, "Yes") == 0)
    {
        ifstream fromFile("PersonalCalendar.txt");
        fromFile.close();

        p.loadFromFile(fromFile);
    }
    cout << "The available commands are: " << endl
         << "-help-(shows you the list of all comands)" << endl
         << "-Add meeting" << endl
         << "-Cancel meeting" << endl
         << "-Daily schedule-(pulls out a daily schedule for a date entered by you) " << endl
         << "-Change meeting-(gives you the opportunity to change a detail of a meeting)" << endl
         << "-Look for a meeting-(gives you the opportunity to look for a meeting which contains the characters you enter)" << endl
         << "-Busyness-(gives you the number of meeting for each day of the week for a period selected by you and saves it in a text file)" << endl
         << "-Find a time slot-(show you the available time slots for a meeting with a duration chosen by you)" << endl
         << "-close-(saves the changes made to a text file)" << endl;
    while (1)
    {
        cout << "Command: ";
        char command[MAX_SIZE];
        cin.getline(command, MAX_SIZE, '\n');
        if (strcmp(command, "help") == 0)
        {
            cout << "The available commands are: " << endl
                 << "-help-(shows you the list of all comands)" << endl
                 << "-Add meeting" << endl
                 << "-Cancel meeting" << endl
                 << "-Daily schedule-(pulls out a daily schedule for a date entered by you) " << endl
                 << "-Change meeting-(gives you the opportunity to change a detail of a meeting)" << endl
                 << "-Look for a meeting-(gives you the opportunity to look for a meeting which contains the characters you enter)" << endl
                 << "-Busyness-(gives you the number of meeting for each day of the week for a period selected by you and saves it in a text file)" << endl
                 << "-Find a time slot-(show you the available time slots for a meeting with a duration chosen by you)" << endl
                 << "-close-(saves the changes made to a text file)" << endl;
        }
        if (strcmp(command, "Add meeting") == 0)
        {
            p.addMeeting();
        }
        if (strcmp(command, "Cancel meeting") == 0)
        {
            p.cancelMeeting();
        }
        if (strcmp(command, "Daily schedule") == 0)
        {
            cout << "Enter the date you want to see the schedule for: " << endl;
            size_t day = 50, month = 0, year = 0;
            while (!isValidDate(day, month, year))
            {
                cout << "Day: ";
                cin >> day;
                cout << "Month: ";
                cin >> month;
                cout << "Year: ";
                cin >> year;
            }
            Date *date = new Date(day, month, year);
            p.daySchedule(*date);
            delete date;
        }
        if (strcmp(command, "Change meeting") == 0)
        {
            p.changeMeeting();
        }
        if (strcmp(command, "Look for a meeting") == 0)
        {
            p.searchForMeetings();
        }
        if (strcmp(command, "Busyness") == 0)
        {
            cout << "Enter the start date of the period that busyness you are looking for: " << endl;
            size_t dayS = 50, monthS = 0, yearS = 0;
            while (!isValidDate(dayS, monthS, yearS))
            {
                cout << "Day: ";
                cin >> dayS;
                cout << "Month: ";
                cin >> monthS;
                cout << "Year: ";
                cin >> yearS;
            }
            Date *dateS = new Date(dayS, monthS, yearS);
            cout << "Enter the end date of the period that busyness you are looking for: " << endl;
            size_t dayE = 50, monthE = 0, yearE = 0;
            while (!isValidDate(dayE, monthE, yearE))
            {
                cout << "Day: ";
                cin >> dayE;
                cout << "Month: ";
                cin >> monthE;
                cout << "Year: ";
                cin >> yearE;
            }
            Date *dateE = new Date(dayE, monthE, yearE);
            p.meetingByDayOfWeek(*dateS, *dateE);
            delete dateS, dateE;
        }
        if (strcmp(command, "Find a time slot") == 0)
        {
            cout << "Enter the start date of the period where you are looking to schedule a meeting: " << endl;
            size_t dayS = 50, monthS = 0, yearS = 0;
            while (!isValidDate(dayS, monthS, yearS))
            {
                cout << "Day: ";
                cin >> dayS;
                cout << "Month: ";
                cin >> monthS;
                cout << "Year: ";
                cin >> yearS;
            }
            Date *dateS = new Date(dayS, monthS, yearS);
            cout << "Enter the end date of the period where you are looking to schedule a meeting: " << endl;
            size_t dayE = 50, monthE = 0, yearE = 0;
            while (!isValidDate(dayE, monthE, yearE))
            {
                cout << "Day: ";
                cin >> dayE;
                cout << "Month: ";
                cin >> monthE;
                cout << "Year: ";
                cin >> yearE;
            }
            Date *dateE = new Date(dayE, monthE, yearE);
            cout << "Enter the duration of the meeting: " << endl;
            size_t hoursD = 24, minutesD = 0, secondsD = 0;
            cout << "Enter the duration (the format is HH/MM/SS): " << endl;
            while (!isValidTime(hoursD, minutesD, secondsD))
            {
                cout << "Hours: ";
                cin >> hoursD;
                cout << "Minutes: ";
                cin >> minutesD;
                cout << "Seconds: ";
                cin >> secondsD;
            }
            Time *duration = new Time(hoursD, minutesD, secondsD);
            cout << "Enter the time range you are most comfortable with: " << endl;
            cout << "Left limit: " << endl;
            size_t hoursLL = 24, minutesLL = 0, secondsLL = 0;
            cout << "Enter the duration (the format is HH/MM/SS): " << endl;
            while (!isValidTime(hoursLL, minutesLL, secondsLL))
            {
                cout << "Hours: ";
                cin >> hoursLL;
                cout << "Minutes: ";
                cin >> minutesLL;
                cout << "Seconds: ";
                cin >> secondsLL;
            }
            Time *leftLimit = new Time(hoursLL, minutesLL, secondsLL);
            size_t hoursRL = 24, minutesRL = 0, secondsRL = 0;
            cout << "Enter the duration (the format is HH/MM/SS): " << endl;
            while (!isValidTime(hoursRL, minutesRL, secondsRL))
            {
                cout << "Hours: ";
                cin >> hoursRL;
                cout << "Minutes: ";
                cin >> minutesRL;
                cout << "Seconds: ";
                cin >> secondsRL;
            }
            Time *rightLimit = new Time(hoursRL, minutesRL, secondsRL);

            p.findFreeTimeSlot(*dateS, *dateE, *duration, *leftLimit, *rightLimit);
            delete rightLimit, leftLimit, dateS, dateE, duration;
        }
        if (strcmp(command, "close") == 0)
        {
            ofstream saveFile("PersonalCalendar.txt", ios::trunc);
            p.saveToFile(saveFile);
            saveFile.close();
            return;
        }
    }
}
int main()
{
    runProgram();
    return 0;
}
