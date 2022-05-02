#include <iostream>
// #include "Time.h"
// #include "Time.cpp"
#include "Date.h"
#include "Date.cpp"
#include "Time.h"
#include "Time.cpp"
#include "Meeting.h"
#include "Meeting.cpp"
int main()
{
    Time begin1(12, 25, 36);
    Time end1(12, 00, 00);
    Date d1(3, 2, 2012);
    Meeting m1;
    enterMeeting(m1);
    writeInFile(m1);

    return 0;
}