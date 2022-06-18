#pragma once
#include <iostream>
#include "Shape.h"
using namespace std;
class Line : public Shape
{
private:
    double mX2;
    double mY2;
    MyString mColour;

public:
    void print() override;
    bool isWithinCircle(double x, double y, double r) override;
    bool isWithinRect(double x, double y, double height, double width) override;
    Line() = default;
    Line(double x2, double y2, char *colour);
};