#include "MyString.h"
#include <cstring>
#include <iostream>
using namespace std;
void MyString::copyFrom(const MyString &other)
{
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
}
void MyString::free()
{
    delete[] str;
}
void MyString::concat(const MyString &other)
{
    char *temp = new char[size + other.size + 1];
    strcpy(temp, str);
    strcpy(temp, other.str);
    delete[] str;
    str = temp;
    size = size + other.size;
}
size_t MyString::getNumSize(size_t num) const
{
    size_t counter = 0;
    while (num > 0)
    {
        counter++;
        num /= 10;
    }
    return counter;
}
MyString::MyString()
{
    str = new char[1];
    str[0] = '\0';
    size = 0;
}
MyString::MyString(const char *data)
{
    if (data == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
        size = 0;
    }
    else
    {
        size = strlen(data);
        str = new char[size + 1];
        strcpy(str, data);
    }
}
MyString::MyString(size_t num)
{
    int numSize = getNumSize(num);
    str = new char[numSize + 1];
    str[numSize] = '\0';

    for (size_t i = 0; i < numSize; i++)
    {
        str[numSize - 1 - i] = (num % 10) + '0';
        num /= 10;
    }
    size = numSize;
}
MyString::MyString(const MyString &other)
{
    copyFrom(other);
}
MyString::MyString(MyString &&other)
{
    str = other.str;
    size = other.size;
    other.str = nullptr;
}
size_t MyString::getSize() const
{
    return size;
}
const char *MyString::getStr() const
{
    return str;
}
MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
MyString &MyString::operator=(MyString &&other)
{
    if (this != &other)
    {
        free();
        str = other.str;
        other.str = nullptr;
        size = other.size;
    }
    return *this;
}
MyString &MyString::operator+=(const MyString &other)
{
    concat(other);
    return *this;
}
std::ostream &operator<<(std::ostream &out, const MyString &other)
{
    return out << other;
}
std::istream &operator>>(std::istream &in, MyString &other)
{
    delete[] other.str;
    char buff[1024];
    in >> buff;
    other.size = strlen(buff);
    other.str = new char[other.size + 1];
    strcpy(other.str, buff);
    return in;
}
MyString::~MyString()
{
    free();
}
MyString operator+(const MyString &lhs, const MyString &rhs)
{
    MyString leftCopy(lhs);
    leftCopy += rhs;
    return leftCopy;
}
bool operator==(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs.getStr(), rhs.getStr()) == 0;
}
bool operator<=(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs.getStr(), rhs.getStr()) <= 0;
}
bool operator<(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs.getStr(), rhs.getStr()) < 0;
}