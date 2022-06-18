#pragma once
#include <iostream>
#include "MyString\MyString.h"
class Shape
{
private:
    double mX;
    double mY;

protected:
    double lengthBtwn2points(double x1, double y1, double x2, double y2);

public:
    virtual void print() = 0;
    virtual bool isWithinCircle(double x, double y, double r) = 0;
    virtual bool isWithinRect(double x, double y, double height, double width) = 0;
    double getX();
    double getY();
    Shape() = default;
    Shape(double x, double y);
    // virtual ~Shape();
};
/*
rect x y heigth width rx ry
circle x y r
line x1 y1 x2 y2
*/