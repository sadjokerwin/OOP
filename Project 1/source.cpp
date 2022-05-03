#include <iostream>
// #include "Time.h"
// #include "Time.cpp"
#include "Date.h"
#include "Date.cpp"
#include "Time.h"
#include "Time.cpp"
#include "Meeting.h"
#include "Meeting.cpp"
#include "PersonalCalendar.h"
#include "PersonalCalendar.cpp"
int main()
{
    // Time begin1(12, 25, 36);
    // Time end1(12, 00, 00);
    // Date d1(3, 2, 2012);
    Meeting m1(enterMeeting());
    // Meeting m2(enterMeeting());
    // m1=enterMeeting();
    // printMeeting(m1);
    // writeInFile(m1);
    personalCalendar p(0,4);
    p.addMeeting(m1);
    // printMeeting(*p.getmCalendar()[0]);
    // p.addMeeting();
    return 0;
}