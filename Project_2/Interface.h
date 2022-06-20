#pragma once
#include <iostream>
#include <cstring>
#include "ShapeCollection.h"
using namespace std;
class Interface
{
    ShapeCollection mShapeCollection;
    public:
    void open(const MyString &fileName);
    void close();
    void save(const MyString &oldFile);
    void saveAs(const MyString &newFile);
    void help() const;
    bool exit();
    void print() const;
    void create();
    void erase();
    void translate();
    void withinCircle() const;
    void withinRectangle() const;
};