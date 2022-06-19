#include "Factory.h"

Shape *Factory::createShape(Shape::shapeType type)
{
    switch (type)
    {
    case Shape::shapeType::Circle:
        return new Circle();
    case Shape::shapeType::Rectangle:
        return new Rectangle();
    case Shape::shapeType::Line:
        return new Line();
    }
    return nullptr;
}