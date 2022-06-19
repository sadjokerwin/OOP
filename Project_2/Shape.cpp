#include <iostream>
#include <cmath>
#include "Shape.h"
using namespace std;
double Shape::lengthBtwn2points(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
double Shape::getX()
{
    return mX;
}
double Shape::getY()
{
    return mY;
}
void Shape::setX(double x)
{
    if (x < 0)
        mX = 0;
    else
        mX = x;
}
void Shape::setY(double y)
{
    if (y < 0)
        mY = 0;
    else
        mY = y;
}
Shape::Shape(double x, double y)
{
    mX = abs(x);
    mY = abs(y);
}
