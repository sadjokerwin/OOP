#include "ShapeCollection.h"
#include <iostream>
using namespace std;
void ShapeCollection::free()
{
    for (int i = 0; i < mShapeCount; i++)
    {
        delete mCollection[i];
    }
    delete[] mCollection;
}
void ShapeCollection::copyFrom(const ShapeCollection &other)
{
    mShapeCount = other.mShapeCount;
    mCapacity = other.mCapacity;
    mCollection = new Shape *[mCapacity];
    for (int i = 0; i < mShapeCount; i++)
    {
        mCollection[i] = other.mCollection[i]->clone();
    }
}
void ShapeCollection::resize()
{
    Shape **newColl = new Shape *[mCapacity *= 2];
    for (int i = 0; i < mShapeCount; i++)
    {
        newColl[i] = mCollection[i];
    }
    delete[] mCollection;
    mCollection = newColl;
}

ShapeCollection::ShapeCollection()
{
    mShapeCount = 0;
    mCapacity = 8;
    mCollection = new Shape *[mCapacity];
}
ShapeCollection::ShapeCollection(const ShapeCollection &other)
{
    copyFrom(other);
}
ShapeCollection &ShapeCollection::operator=(const ShapeCollection &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
size_t ShapeCollection::getShapeCount() const
{
    return mShapeCount;
}
Shape **ShapeCollection::getCollection() const
{
    return mCollection;
}
void ShapeCollection::print() const
{
    for (int i = 0; i < mShapeCount; i++)
    {
        cout << i << ". ";
        mCollection[i]->print();
    }
}
void ShapeCollection::addAnimal(const Shape &other)
{
    if (mShapeCount + 1 >= mCapacity)
        resize();
    mCollection[mShapeCount++] = other.clone();
}
void ShapeCollection::addAnimal(Shape::shapeType type)
{
    Shape *newShape = shapeFactory.createShape(type);
    if (newShape != nullptr)
    {
        if (mShapeCount + 1 >= mCapacity)
            resize();
        mCollection[mShapeCount++] = newShape;
    }
}
void ShapeCollection::erase(size_t index)
{
    if (index > mShapeCount)
        cout << "There is no figure number " << index << "!";
    mCollection[index - 1] = nullptr;
    for (int i = index - 1; i < mShapeCount; i++)
    {
        swap(mCollection[i], mCollection[i + 1]);
    }
    mShapeCount--;
}
void ShapeCollection::translate(size_t index, double vertTransl, double horizTransl)
{
    if (index != 0)
    {
        mCollection[index - 1]->translate(vertTransl, horizTransl);
    }
    else
    {
        for (int i = 0; i < mShapeCount; i++)
        {
            mCollection[i]->translate(vertTransl, horizTransl);
        }
    }
}
void ShapeCollection::withinCircle(double x, double y, double r) const
{
    bool isEmpty = 1;
    for (int i = 0; i < mShapeCount; i++)
    {
        if (mCollection[i]->isWithinCircle(x, y, r))
        {
            cout << i << ". ";
            mCollection[i]->print();
            isEmpty = false;
        }
    }
    if (isEmpty)
        cout << "No figures are located within circle " << x << " " << y << " " << r;
}
void ShapeCollection::withinRect(double x, double y, double height, double width) const
{
    bool isEmpty = 1;
    for (int i = 0; i < mShapeCount; i++)
    {
        if (mCollection[i]->isWithinRect(x, y, height, width))
        {
            cout << i << ". ";
            mCollection[i]->print();
            isEmpty = false;
        }
    }
    if (isEmpty)
        cout << "No figures are located within rectangle " << x << " " << y << " " << height << " " << width;
}
ShapeCollection::~ShapeCollection()
{
    free();
}