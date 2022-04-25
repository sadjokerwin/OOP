#include <iostream>
#include "Time.h"
#include "Time.cpp"
int main()
{
    Time t1(12, 25, 36);
    Time t2(12, 00, 00);
    Time t3;
    t3 = t1 - t2;
    cout << t3;
    // cout << t3.getHours() << ":" << t3.getMins() << ":" << t3.getSeconds();
    return 0;
}