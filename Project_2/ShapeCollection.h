#pragma once
#include "Shape.h"
#include "Factory.h" 
class ShapeCollection
{
    Shape **mCollection;
    size_t mShapeCount;
    size_t mCapacity;
    void free();
    void copyFrom(const ShapeCollection &other);
    void resize();
    
    Factory shapeFactory;

public:
    ShapeCollection();
    ShapeCollection(const ShapeCollection &other);
    ShapeCollection &operator=(const ShapeCollection &other);
    size_t getShapeCount() const;
    Shape**getCollection() const;

    void print() const;

    void addAnimal(const Shape &other);
    void addAnimal(Shape::shapeType type);

    void erase(size_t index);
    void translate(size_t index, double vertTransl, double horizTransl);
    
    void withinCircle(double x, double y, double r) const;
    void withinRect(double x, double y, double height, double width) const;
   

    ~ShapeCollection();
};