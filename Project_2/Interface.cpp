#include <iostream>
#include "Interface.h"
using namespace std;
void Interface::open(const MyString &fileName)
{
    ifstream file(fileName.getStr());
    mShapeCollection.loadData(file);
    file.close();
}
void Interface::save(const MyString &oldFile)
{
    ofstream file(oldFile.getStr(), ios::trunc);
    mShapeCollection.save(file);
    file.close();
}
void Interface::saveAs(const MyString &newFile)
{
    ofstream file(newFile.getStr(), ios::trunc);
    mShapeCollection.save(file);
}
void Interface::help() const
{
}
bool Interface::exit()
{
    return 0;
}
void Interface::print() const
{
    mShapeCollection.print();
}
void Interface::create()
{
    cout << "What shape would you like to create: (0-2)" << endl;
    int num;
    cin >> num;
    mShapeCollection.addShape(num);
}
void Interface::erase()
{
    int index;
    cin >> index;
    mShapeCollection.erase(index);
}
void Interface::translate()
{
    size_t index;
    double vertTransl, horizTransl;
    cin >> index >> vertTransl >> horizTransl;
    mShapeCollection.translate(index, vertTransl, horizTransl);
}
void Interface::withinCircle() const
{
    double x, y, r;
    cin >> x >> y >> r;
    mShapeCollection.withinCircle(x, y, r);
}
void Interface::withinRectangle() const
{
    double x, y, height, width;
    cin >> x >> y >> height >> width;
    mShapeCollection.withinRect(x, y, height, width);
}