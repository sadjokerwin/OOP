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
    Shape *clone() const override;
    void print() override;
    void setR(double r);
    void setColour(const char *colour);
    void setColour(MyString& colour);
    void saveToFile(std::ostream &out) override;
    void translate(double vertTransl, double horizTransl) override;
    bool isWithinCircle(double x, double y, double r) override;
    bool isWithinRect(double x, double y, double height, double width) override;
    Circle();
    Circle(double x, double y, double r, char *colour);
};