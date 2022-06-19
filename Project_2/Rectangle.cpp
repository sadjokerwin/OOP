#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
using namespace std;
void Rectangle::print()
{
    cout << "The rectangle has coordinates for upper left corner - (" << getX() << "," << getY() << ")"
         << ", height of  " << mHeight << ", width of " << mWidth << " and is " << mColour << "in colour." << endl;
}
void Rectangle::translate(size_t index, double vertTransl, double horizTransl)
{
    setX(getX() + horizTransl);
    setY(getY() + vertTransl);
}
bool Rectangle::isWithinCircle(double x, double y, double r)
{
    return (r >= lengthBtwn2points(x, y, getX(), getY())) &&
           (r >= lengthBtwn2points(x, y, getX() + mWidth, getY())) &&
           (r >= lengthBtwn2points(x, y, getX() + mHeight, getY() + mWidth)) &&
           (r >= lengthBtwn2points(x, y, getX(), getY() + mWidth));
}
bool Rectangle::isWithinRect(double x, double y, double height, double width)
{
    return ((getX()) >= x) &&
           ((getX()) <= x + width) &&
           ((getY()) >= y) &&
           ((getY()) <= y + height);
}
double Rectangle::getHeight() const
{
    return mHeight;
}
double Rectangle::getWidth() const
{
    return mWidth;
}
Rectangle::Rectangle(double x, double y, double height, double width, char *colour, double rx, double ry) : Shape(x, y)
{
    mHeight = height;
    mWidth = width;
    mColour = colour;
    mRx = rx;
    mRy = ry;
}