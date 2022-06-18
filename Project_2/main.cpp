#include <iostream>

#include "MyString\MyString.h"
#include "MyString\MyString.cpp"

#include "Shape.h"
#include "Shape.cpp"

#include "Rectangle.h"
#include "Rectangle.cpp"

#include "Circle.h"
#include "Circle.cpp"

using namespace std;
int main()
{
    Rectangle r1(225, 255, 60, 80, "pink");
    Circle c1(20, 230, 64, "black");
    // cout << boolalpha << c1.isWithinRect(200, 200, 200, 400);
    // cout<<c1.lenghtBtwn2points(0, 0, 3, 4);
    cout << boolalpha << r1.isWithinRect(200, 200, 200, 400) << endl;
}