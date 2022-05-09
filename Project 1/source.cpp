#include <iostream>
#include <fstream>
#include "Date.h"
#include "Date.cpp"
#include "Time.h"
#include "Time.cpp"
#include "Meeting.h"
#include "Meeting.cpp"
#include "PersonalCalendar.h"
#include "PersonalCalendar.cpp"
using namespace std;
int main()
{
    Date d1(4, 5, 2022);
    Time beg1(0, 45, 0);
    Time end1(0, 55, 0);
    Meeting m1("Hodene do kenefa", "shte se sere mujkata", d1, beg1, end1);
    
    Date d2(6, 10, 2022);
    Time beg2(20, 0, 0);
    Time end2(20, 48, 0);
    Meeting m2("Qdene na duner", "kisnene na opashkata na fantasia", d2, beg2, end2);
    
    Date d3(6, 10, 2022);
    Time beg3(20, 49, 0);
    Time end3(21, 48, 0);
    Meeting m3("Ebane na gadjeto", "shte plushitm qko", d3, beg3, end3);

    Date d4(6, 10, 2022);
    Time beg4(20, 49, 0);
    Time end4(21, 48, 0);
    Meeting m4("Ebane na gadjeto", "shte plushitm qko", d4, beg4, end4);
    personalCalendar p(0, 16);
    p.addMeeting(m1);
    p.addMeeting(m2);
    p.addMeeting(m3);
    p.changeMeeting();
    printMeeting(*p.getmCalendar()[1]);
    // p.addMeeting();
    // printMeeting(*p.getmCalendar()[0]);
    // p.cancelMeeting();
    // cout << p.getMeetingCount();
    // p.daySchedule(d2);
    // for (int i = 0; i < p.getMeetingCount(); i++)
    // {
    //     printMeeting(*p.getmCalendar()[i]);
    // }
    // printMeeting(m1);
    // writeInFile(m1);
    return 0;
}