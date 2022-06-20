#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
using namespace std;
bool Circle::isValid(double x, double y, double r)
{
    return (x - r) > 0 || (y - r) > 0;
}
Shape *Circle::clone() const
{
    Shape *cloneObj = new Circle(*this);
    return cloneObj;
}
void Circle::print()
{
    cout << "The circle has center coordinates - (" << getX() << "," << getY() 
    << ") a radius of "<< mR 
    << " and is " << mColour << " in colour." << endl;
}
void Circle::setR(double r)
{
    mR = r;
}
void Circle::setColour(const char *colour)
{
    mColour = colour;
}
void Circle::setColour(MyString &colour)
{
    mColour = colour;
}
void Circle::saveToFile(std::ostream &out)
{
    out <<endl<< "<circle cx=\"" << getX() << "\" cy=\"" << getY() << "\" r=\"" << mR << "\" fill=\"" << mColour << "\" />";
}
void Circle::translate(double vertTransl, double horizTransl)
{
    if (getX()+horizTransl<0)
        setX(mR);
    else
        setX(getX() + horizTransl);
    if (getY() + horizTransl < 0)
        setY(mR);
    else
        setY(getY() + horizTransl);
}
bool Circle::isWithinCircle(double x, double y, double r)
{
    return r >= (lengthBtwn2points(x, y, getX(), getY()) + mR);
}
bool Circle::isWithinRect(double x, double y, double height, double width)
{
    return ((getX() - mR) >= x) &&
           ((getX() + mR) <= x + width) &&
           ((getY() - mR) >= y) &&
           ((getY() + mR) <= y + height);
}
Circle::Circle():Shape()
{
    mR = 0;
    mColour = "/0";
    currType = Shape::shapeType::Circle;
}
Circle::Circle(double x, double y, double r, char *colour) : Shape(x, y)
{
    mR = r;
    mColour = colour;
}