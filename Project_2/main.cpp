#include <iostream>

#include "MyString\MyString.h"
#include "MyString\MyString.cpp"

#include "Shape.h"
#include "Shape.cpp"

#include "Rectangle.h"
#include "Rectangle.cpp"

#include "Circle.h"
#include "Circle.cpp"

#include "Line.h"
#include "Line.cpp"

#include "ShapeCollection.h"
#include "ShapeCollection.cpp"

#include "Factory.cpp"

using namespace std;
int main()
{
    ShapeCollection coll;
    ifstream file("124.svg");
    coll.loadData(file);
    coll.print();
    ofstream file1((const char *)"126.svg", ios::trunc);
    coll.save(file1);

    // MyString test("220.3");
    // cout << endl<<test.strToDouble();
    return 0;
}