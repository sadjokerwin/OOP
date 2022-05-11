#include <iostream>
#include <fstream>
#include <cstring>
#include "Date.h"
#include "Date.cpp"
#include "Time.h"
#include "Time.cpp"
#include "Meeting.h"
#include "Meeting.cpp"
#include "PersonalCalendar.h"
#include "PersonalCalendar.cpp"
using namespace std;
char* t2urnIntoFileName(const Date &periodBegin)
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

    Date d3(4, 10, 2022);
    Time beg3(20, 49, 0);
    Time end3(21, 48, 0);
    Meeting m3("Ebane na gadjeto", "shte plushitm qko", d3, beg3, end3);

    Date d4(29, 9, 2022);
    Time beg4(20, 49, 0);
    Time end4(21, 48, 0);
    Meeting m4("Ebane na gadjeto", "shte plushitm qko", d4, beg4, end4);

    Date d5(22, 9, 2022);
    Time beg5(20, 49, 0);
    Time end5(21, 48, 0);
    Meeting m5("Ebane na gadjeto", "shte plushitm qko", d5, beg5, end5);

    Date d6(6, 10, 2022);
    Time beg6(20, 49, 0);
    Time end6(21, 48, 0);
    Meeting m6("Ebane na gadjeto", "shte plushitm qko", d6, beg6, end6);
    Time test(0, 2, 30);
    Time testB;
    Time testE(23, 59, 59);
    // cout << test;
    // cout << boolalpha<<(strcmp("2022-06-10.txt", test) == 0);
    personalCalendar p(0, 16);
    // int a = 0;
    p.addMeeting(m1);
    p.addMeeting(m2);
    p.addMeeting(m3);
    p.addMeeting(m4);
    p.addMeeting(m5);
    p.addMeeting(m6);
    p.findFreeTimeSlot(d3, d6, test, testB, testE);
    // p.meetingByDayOfWeek(d5, d2);
    // cout << (m3 - m1);
    // p.searchForMeetings();
    // p.changeMeeting();
    // printMeeting(*p.getmCalendar()[1]);
    // for (int i = 0; i < p.getMeetingCount(); i++)
    // {
    //     printMeeting(*p.getmCalendar()[i]);
    // }
    // printMeeting(m1);
    // writeInFile(m1);
    return 0;
}
