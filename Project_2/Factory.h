#pragma once
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
class Factory
{public:
    virtual Shape *createShape(Shape::shapeType type);
};