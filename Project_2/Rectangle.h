#pragma once
#include <iostream>
#include "Shape.h"
using namespace std;
class Rectangle : public Shape
{
protected:
    double mHeight;
    double mWidth;
    double mRx;
    double mRy;
    MyString mColour;

public:
    void print() override;
    bool isWithinCircle(double x, double y, double r) override;
    bool isWithinRect(double x, double y, double height, double width) override;
    double getHeight() const;
    double getWidth() const;
    Rectangle() = default;
    Rectangle(double x, double y, double height, double width, char *colour, double rx = 0, double ry = 0);
};