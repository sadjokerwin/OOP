#pragma once
#include "Line.h"
#include <iostream>
using namespace std;
Shape *Line::clone() const
{
    Shape *cloneObj = new Line(*this);
    return cloneObj;
}
void Line::print()
{
    cout << "The line has coordinates for point A(" << getX() << "," << getY() << ")"
         << " and coordinates for point B(" << mX2 << "," << mY2 << ")"<< " and is "
         << mColour << " in colour." << endl;
}
void Line::saveToFile(std::ostream &out)
{
    out << endl
        << "<line x1=\"" << getX() << "\" y1=\"" << getY() << "\" x2=\"" << mX2 << "\" y2=\"" << mY2 << "\" stroke=\""<<mColour<<"\" />";
    //<line x1="200" y1="200" x2="230" y2="300"
}
void Line::setX2(double x)
{
    if (x < 0)
        mX2 = 0;
    else
        mX2 = x;
}
void Line::setY2(double y)
{
    if (y < 0)
        mY2 = 0;
    else
        mY2 = y;
}
void Line::translate(double vertTransl, double horizTransl)
{
    setX(getX() + horizTransl);
    setY(getY() + vertTransl);
    setX2(mX2 + horizTransl);
    setY2(mY2 + vertTransl);
}
bool Line::isWithinCircle(double x, double y, double r)
{
    return r >= (lengthBtwn2points(x, y, getX(), getY())) && r >= (lengthBtwn2points(x, y, mX2, mY2));
}
bool Line::isWithinRect(double x, double y, double height, double width)
{
    return ((getX()) >= x) &&
           ((getX()) <= x + width) &&
           ((getY()) >= y) &&
           ((getY()) <= y + height) && 
           ((mX2) >= x) &&
           ((mX2) <= x + width) &&
           ((mY2) >= y) &&
           ((mY2) <= y + height);
}
Line::Line() : Shape()
{
    mX2 = 0;
    mY2 = 0;
    mColour = "/0";
    currType = Shape::shapeType::Line;
}
Line::Line(double x1, double y1, double x2, double y2, char *colour) : Shape(x1, y1)
{
    mX2 = x2;
    mY2 = y2;
    mColour = colour;
}