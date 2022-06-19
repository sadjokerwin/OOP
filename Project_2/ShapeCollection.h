#pragma once
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include <vector>
class ShapeCollection
{
    Shape **mCollection;
    size_t mShapeCount;
    size_t mCapacityl;
};