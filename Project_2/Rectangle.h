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
    Shape *clone() const override;
    void print() override;
    void setHeight(double height);
    void setWidth(double width);
    void setRx(double rx);
    void setRy(double ry);
    void setColour(const char *colour);
    void setColour(MyString &colour);
    void saveToFile(std::ostream &out) override;
    void translate(double vertTransl, double horizTransl) override;
    bool isWithinCircle(double x, double y, double r) override;
    bool isWithinRect(double x, double y, double height, double width) override;

    double getHeight() const;
    double getWidth() const;
    Rectangle();
    Rectangle(double x, double y, double height, double width, char *colour, double rx = 0, double ry = 0);
};