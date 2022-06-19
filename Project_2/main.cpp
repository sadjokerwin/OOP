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

// #include "ShapeCollection.h"
// #include "ShapeCollection.cpp"

// #include "Factory.cpp"

using namespace std;
int main()
{
    Rectangle r1(225, 255, 60, 80, "pink");
    Circle c1(20, 230, 64, "red");
    Line l1(100, 100, 230, 300, "black");
    // l1.translate(0, -10, 10);
    // l1.print();
    // ShapeCollection coll;
    /*coll.addAnimal(r1);
    coll.addAnimal(c1);
    coll.addAnimal(l1);
    coll.getCollection()[0]->print();
    coll.getCollection()[1]->print();
    coll.getCollection()[2]->print();
    coll.erase(2);
    coll.getCollection()[0]->print();
    coll.getCollection()[1]->print();*/
    // cout << boolalpha << c1.isWithinRect(200, 200, 200, 400);
    // cout<<c1.lenghtBtwn2points(0, 0, 3, 4);
    // cout << boolalpha << r1.isWithinRect(200, 200, 200, 400) << endl;
    // cout << boolalpha << l1.isWithinCircle(250, 230, 75) << endl;
    // cout << boolalpha << l1.isWithinRect(175, 175, 60, 80) << endl;
    std::ofstream file("124.svg", ios::app);
    l1.saveToFile(file);
    // r1.saveToFile(file);
    file <<endl<< "</svg>";
}