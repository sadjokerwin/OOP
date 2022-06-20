#include "ShapeCollection.h"
#include <iostream>
#include <cstring>
#include <cmath>
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
bool ShapeCollection::isCircleInFile(const char *str)
{
    MyString temp(str);
    bool cxEmpty = 1, cyEmpty = 1, rEmpty = 1, fillEmpty = 1;
    // cout << temp << endl;
    size_t index = temp.charInString('<');
    if (temp.subString("circle") != -1)
    {
        for (int i = index + 1; i < temp.subString("circle"); i++)
        {
            if (temp.getStr()[i] != ' ')
            {
                cout << "false1";
                return false;
            }
        }
    }
    else
    {
        cout << "false2";
        return false;
    }
    Circle c1;
    MyString cx, cy, cr, colour;
    int counter = temp.subString("circle") + 6;
    while (counter < temp.getSize())
    {
        switch (temp.getStr()[counter])
        {
        case 'c':
            counter++;
            if ((temp.getStr()[counter] == 'x') && (cxEmpty = 1))
            {
                counter++;
                // while (temp.getStr()[counter] != '=')
                // {
                //     // if (temp.getStr()[counter] != ' ')
                //     // {
                //     //     cout << "false3";
                //     //     return false;
                //     // }
                //     counter++;
                // }
                // counter++;
                // cout << temp.getStr()[counter];
                while (temp.getStr()[counter] != '\"')
                {
                    // if (temp.getStr()[counter] != ' ')
                    // {
                    //     cout << "false4";
                    //     return false;
                    // }
                    counter++;
                }
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    // cout << temp.getStr()[counter];
                    if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                    {
                        cout << "false5";
                        return false;
                    }
                    else
                    {
                        if (temp.getStr()[counter] != ' ')
                        {
                            // cout << temp.getStr()[counter];
                            cx += temp.getStr()[counter];
                        }
                        counter++;
                    }
                }
                // cout << "Cx=" << cx << endl;
                // cout << cx.strToDouble();
                c1.setX(cx.strToDouble());
            }
            else if ((temp.getStr()[counter] == 'y') && (cyEmpty = 1))
            {
                // cout << "vliza za y";
                counter++;
                // while (temp.getStr()[counter] != '=')
                // {
                //     // if (temp.getStr()[counter] != ' ')
                //     // {
                //     //     cout << "false6";
                //     //     return false;
                //     // }
                //     counter++;
                // }
                // counter++;
                // cout << temp.getStr()[counter];
                while (temp.getStr()[counter] != '\"')
                {
                    // if (temp.getStr()[counter] != ' ')
                    // {
                    //     cout << "false7";
                    //     return false;
                    // }
                    counter++;
                }
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    // cout << "vliza";
                    if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                    {
                        cout << "false7";
                        return false;
                    }
                    else
                    {
                        if (temp.getStr()[counter] != ' ')
                        {
                            // cout << temp.getStr()[counter];
                            cy += temp.getStr()[counter];
                        }
                        counter++;
                    }
                }
                // cout << "Cy=" << cy << endl;
                // cout << cy.strToDouble();
                c1.setY(cy.strToDouble());
            }
            else
            {
                cout << "false8";
                return false;
            }
            break;
        case 'r':
            counter++;
            while (temp.getStr()[counter] != '=')
            {
                // if (temp.getStr()[counter] != ' ')
                // {
                //     cout << "false9";
                //     return false;
                // }
                counter++;
            }
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                // if (temp.getStr()[counter] != ' ')
                // {
                //     cout << "false10";
                //     return false;
                // }
                counter++;
            }
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                {
                    cout << "false11";
                    return false;
                }
                else
                {
                    if (temp.getStr()[counter] != ' ')
                        cr += temp.getStr()[counter];
                    counter++;
                }
            }
            // cout << "Cr=" << cr << endl;
            c1.setR(cr.strToDouble());
            break;
        case 'f':
            // cout << "vliza colour";
            counter += 3;
            while (temp.getStr()[counter] != '\"')
            {
                // cout << "vliza";
                counter++;
            }
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                // cout << "vliza";
                if (temp.getStr()[counter] < 'A' && temp.getStr()[counter] > 'Z' && temp.getStr()[counter] < 'a' && temp.getStr()[counter] > 'z')
                {
                    cout << "falseColour";
                    return false;
                }
                else
                {
                    if (temp.getStr()[counter] != ' ')
                    {
                        // cout << temp.getStr()[counter];
                        colour += temp.getStr()[counter];
                    }
                    counter++;
                }
            }
            // cout << colour;
            c1.setColour(colour);
            break;
        case '/':
            counter++;
            if (temp.getStr()[counter] != '>')
                continue;
        default:
            counter++;
            break;
        }
    }
    // c1.print();
    addShape(c1);
}
bool ShapeCollection::isRectInFile(const char *str)
{
    MyString temp(str);
    cout << temp << endl;
    size_t index = temp.charInString('<');
    if (temp.subString("rect") != -1)
    {
        for (int i = index + 1; i < temp.subString("rect"); i++)
        {
            if (temp.getStr()[i] != ' ')
            {
                cout << "false1";
                return false;
            }
        }
    }
    else
    {
        cout << "false2";
        return false;
    }
    Rectangle r1;
    MyString x, y, height, width, rx, ry, colour;
    int counter = temp.subString("rect") + 4;
    while (counter < temp.getSize())
    {
        switch (temp.getStr()[counter])
        {
        case 'x':
            cout << "vliza x";
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                counter++;
            }
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                // cout << temp.getStr()[counter];
                if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                {
                    cout << "false5";
                    return false;
                }
                else
                {
                    if (temp.getStr()[counter] != ' ')
                    {
                        // cout << temp.getStr()[counter];
                        x += temp.getStr()[counter];
                    }
                    counter++;
                }
            }
            r1.setX(x.strToDouble());
            break;
        case 'y':
            cout << "vliza y";
            // cout << temp.getStr()[counter];
            while (temp.getStr()[counter] != '\"')
            {
                counter++;
            }
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                {
                    cout << "false7";
                    return false;
                }
                else
                {
                    if (temp.getStr()[counter] != ' ')
                    {
                        // cout << temp.getStr()[counter];
                        y += temp.getStr()[counter];
                    }
                    counter++;
                }
            }
            cout << y.strToDouble();
            r1.setY(y.strToDouble());
            break;
        case 'h':
            cout << "vliza h";
            while (temp.getStr()[counter] != '\"')
            {
                counter++;
            }
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                {
                    cout << "false11";
                    return false;
                }
                else
                {
                    if (temp.getStr()[counter] != ' ')
                        height += temp.getStr()[counter];
                    counter++;
                }
            }
            // cout << "Height=" << height << endl;
            r1.setHeight(height.strToDouble());
            break;
        case 'w':
            cout << "vliza w";
            while (temp.getStr()[counter] != '\"')
            {
                counter++;
            }
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                {
                    cout << "false11";
                    return false;
                }
                else
                {
                    if (temp.getStr()[counter] != ' ')
                        width += temp.getStr()[counter];
                    counter++;
                }
            }
            // cout << "Width=" << width << endl;
            r1.setWidth(width.strToDouble());
            break;
        case 'r':
            cout << "vliza r";
            counter++;
            if ((temp.getStr()[counter] == 'x'))
            {
                while (temp.getStr()[counter] != '\"')
                {
                    counter++;
                }
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    // cout << temp.getStr()[counter];
                    if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                    {
                        cout << "false5";
                        return false;
                    }
                    else
                    {
                        if (temp.getStr()[counter] != ' ')
                        {
                            // cout << temp.getStr()[counter];
                            rx += temp.getStr()[counter];
                        }
                        counter++;
                    }
                }
                // cout << "Rx=" << rx << endl;
                // cout << cx.strToDouble();
                r1.setRx(rx.strToDouble());
            }
            else
            {
               
                while (temp.getStr()[counter] != '\"')
                {

                    counter++;
                }
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    // cout << "vliza";
                    if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                    {
                        cout << "false7";
                        return false;
                    }
                    else
                    {
                        if (temp.getStr()[counter] != ' ')
                        {
                            // cout << temp.getStr()[counter];
                            ry += temp.getStr()[counter];
                        }
                        counter++;
                    }
                }
                // cout << "Ry=" << ry << endl;
                // cout << cy.strToDouble();
                r1.setRy(ry.strToDouble());
            }
            break;
        case 'f':
            cout << "vliza f";
            counter += 3;
            while (temp.getStr()[counter] != '\"')
            {
                // cout << "vliza";
                counter++;
            }
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                // cout << "vliza";
                if (temp.getStr()[counter] < 'A' && temp.getStr()[counter] > 'Z' && temp.getStr()[counter] < 'a' && temp.getStr()[counter] > 'z')
                {
                    cout << "falseColour";
                    return false;
                }
                else
                {
                    if (temp.getStr()[counter] != ' ')
                    {
                        // cout << temp.getStr()[counter];
                        colour += temp.getStr()[counter];
                    }
                    counter++;
                }
            }
            // cout << "colour: "<<colour;
            r1.setColour(colour);
            break;
        case '/':
            counter++;
            if (temp.getStr()[counter] != '>')
                continue;
        default:
            counter++;
            break;
        }
    }
    r1.print();
    addShape(r1);
}
bool ShapeCollection::isLineInFile(const char *str)
{
    MyString temp(str);
    // cout << temp << endl;
    size_t index = temp.charInString('<');
    if (temp.subString("line") != -1)
    {
        for (int i = index + 1; i < temp.subString("line"); i++)
        {
            if (temp.getStr()[i] != ' ')
            {
                cout << "false1";
                return false;
            }
        }
    }
    else
    {
        cout << "false2";
        return false;
    }
    Line l1;
    MyString x1, y1, x2, y2, colour;
    int counter = temp.subString("line") + 4;
    ;
    while (counter < temp.getSize())
    {
        switch (temp.getStr()[counter])
        {
        case 'x':
            counter++;
            if ((temp.getStr()[counter] == '1'))
            {
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    counter++;
                }
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    // cout << temp.getStr()[counter];
                    if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                    {
                        cout << "false5";
                        return false;
                    }
                    else
                    {
                        if (temp.getStr()[counter] != ' ')
                        {
                            // cout << temp.getStr()[counter];
                            x1 += temp.getStr()[counter];
                        }
                        counter++;
                    }
                }
                // cout << "Rx=" << rx << endl;
                // cout << cx.strToDouble();
                l1.setX(x1.strToDouble());
            }
            else
            {
                counter++;
                while (temp.getStr()[counter] != '\"')
                {

                    counter++;
                }
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    // cout << "vliza";
                    if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                    {
                        cout << "false7";
                        return false;
                    }
                    else
                    {
                        if (temp.getStr()[counter] != ' ')
                        {
                            // cout << temp.getStr()[counter];
                            x2 += temp.getStr()[counter];
                        }
                        counter++;
                    }
                }
                // cout << "Ry=" << ry << endl;
                // cout << cy.strToDouble();
                l1.setX2(x2.strToDouble());
            }
            break;
        case 'y':
            counter++;
            if ((temp.getStr()[counter] == '1'))
            {
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    counter++;
                }
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    // cout << temp.getStr()[counter];
                    if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                    {
                        cout << "false5";
                        return false;
                    }
                    else
                    {
                        if (temp.getStr()[counter] != ' ')
                        {
                            // cout << temp.getStr()[counter];
                            y1 += temp.getStr()[counter];
                        }
                        counter++;
                    }
                }
                // cout << "Rx=" << rx << endl;
                // cout << cx.strToDouble();
                l1.setY(y1.strToDouble());
            }
            else
            {
                counter++;
                while (temp.getStr()[counter] != '\"')
                {

                    counter++;
                }
                counter++;
                while (temp.getStr()[counter] != '\"')
                {
                    // cout << "vliza";
                    if (temp.getStr()[counter] < '0' && temp.getStr()[counter] > '9' && temp.getStr()[counter] != '.')
                    {
                        cout << "false7";
                        return false;
                    }
                    else
                    {
                        if (temp.getStr()[counter] != ' ')
                        {
                            // cout << temp.getStr()[counter];
                            y2 += temp.getStr()[counter];
                        }
                        counter++;
                    }
                }
                // cout << "Ry=" << ry << endl;
                // cout << cy.strToDouble();
                l1.setY2(y2.strToDouble());
            }
            break;
        case 's':
            counter += 5;
            while (temp.getStr()[counter] != '\"')
            {
                // cout << "vliza";
                counter++;
            }
            counter++;
            while (temp.getStr()[counter] != '\"')
            {
                // cout << "vliza";
                if (temp.getStr()[counter] < 'A' && temp.getStr()[counter] > 'Z' && temp.getStr()[counter] < 'a' && temp.getStr()[counter] > 'z')
                {
                    cout << "falseColour";
                    return false;
                }
                else
                {
                    if (temp.getStr()[counter] != ' ')
                    {
                        // cout << temp.getStr()[counter];
                        colour += temp.getStr()[counter];
                    }
                    counter++;
                }
            }
            // cout << "colour: "<<colour;
            l1.setColour(colour);
            break;
        case '/':
            counter++;
            if (temp.getStr()[counter] != '>')
                continue;
        default:
            counter++;
            break;
        }
    }
    // c1.print();
    addShape(l1);
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
        cout << i + 1 << ". ";
        mCollection[i]->print();
    }
}
void ShapeCollection::addShape(const Shape &other)
{
    if (mShapeCount + 1 >= mCapacity)
        resize();
    mCollection[mShapeCount++] = other.clone();
}
void ShapeCollection::addShape(Shape::shapeType type)
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
bool ShapeCollection::loadData(std::ifstream &fromFile)
{
    while (!fromFile.eof())
    {
        char buffer[1024];
        fromFile.getline(buffer, 1024, '\n');
        cout << "------------" << buffer << "------------" << endl;
        if (isCircleInFile(buffer))
        {
            cout << "Loaded Circle " << endl;
        }
        else if (isRectInFile(buffer))
        {
            cout << "Loaded Rect " << endl;
        }
        else if (isLineInFile(buffer))
        {
            cout << "Loaded Line " << endl;
        }else
            cout << "Not supported shape" << endl;
    }
    fromFile.close();
}
void ShapeCollection::save(std::ofstream &toFile)
{
    toFile << "<?xml version=\"1.0\" standalone=\"no\"?>" 
    <<endl 
    << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">";
    for (int i = 0; i < mShapeCount; i++)
    {
        mCollection[i]->saveToFile(toFile);
    }
    toFile << "</svg>";
}
/*
<?xml version="1.0" standalone="no"?>
<svg xmlns="http://www.w3.org/2000/svg"  version="1.1">
*/
ShapeCollection::~ShapeCollection()
{
    free();
}