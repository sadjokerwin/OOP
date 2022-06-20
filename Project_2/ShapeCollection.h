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
    bool isCircleInFile(const char *str);
    bool isRectInFile(const char *str);
    bool isLineInFile(const char *str);
    ShapeCollection();
    ShapeCollection(const ShapeCollection &other);
    ShapeCollection &operator=(const ShapeCollection &other);
    size_t getShapeCount() const;
    Shape**getCollection() const;

    void print() const;

    void addShape(const Shape &other);
    void addShape(Shape::shapeType type);

    void erase(size_t index);
    void translate(size_t index, double vertTransl, double horizTransl);
    
    void withinCircle(double x, double y, double r) const;
    void withinRect(double x, double y, double height, double width) const;

    bool loadData(std::ifstream& fromFile);

    void save(std::ofstream &toFile);
    
    ~ShapeCollection();
};