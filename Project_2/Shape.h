#pragma once
#include <iostream>
#include "MyString\MyString.h"
class Shape
{
private:
    double mX;
    double mY;

public:
    enum shapeType
    {
        Circle = 0,
        Rectangle = 1,
        Line = 2
    };
    virtual Shape *clone() const = 0;
    virtual void print() = 0;
    virtual void saveToFile(std::ostream& out) = 0;
    virtual void translate( double vertTransl, double horizTransl) = 0;
    virtual bool isWithinCircle(double x, double y, double r) = 0;
    virtual bool isWithinRect(double x, double y, double height, double width) = 0;
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
    Shape() = default;
    Shape(double x, double y);
    virtual ~Shape() = default;

protected:
    double lengthBtwn2points(double x1, double y1, double x2, double y2);
    shapeType currType;
};
/*
rect x y heigth width rx ry
circle x y r
line x1 y1 x2 y2
*/