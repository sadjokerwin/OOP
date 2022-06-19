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
    void setX2(double x);
    void setY2(double y);
    void translate(size_t index = 0, double vertTransl =0 , double horizTransl = 0) override;
    bool isWithinCircle(double x, double y, double r) override;
    bool isWithinRect(double x, double y, double height, double width) override;
    Line() = default;
    Line(double x1, double y1, double x2, double y2, char *colour);
};