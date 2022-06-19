#pragma once
#include <iostream>
#include "Shape.h"
using namespace std;
class Circle : public Shape
{
private:
    double mR;
    MyString mColour;
    bool isValid(double x, double y, double r);

public:
    void print() override;
    void translate(size_t index, double vertTransl, double horizTransl) override;
    bool isWithinCircle(double x, double y, double r) override;
    bool isWithinRect(double x, double y, double height, double width) override;
    Circle() = default;
    Circle(double x, double y, double r, char *colour);
};