#include "MyString.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void MyString::copyFrom(const MyString &other)
{
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
}
void MyString::free()
{
    delete str;
}
void MyString::concat(const MyString &other)
{
    char *temp = new char[getSize() + other.getSize() + 1];
    strcpy(temp, str);
    strcat(temp, other.str);
    delete[] str;
    str = temp;
    size = size + other.getSize();
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
MyString::MyString(const char symbol)
{
    str = new char[2];
    size = 1;
    str[0] = symbol;
    str[1] = '\0';
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
MyString &MyString::operator+=(char symbol)
{
    MyString sym(symbol);
    concat(sym);
    return *this;
}
std::ostream &operator<<(std::ostream &out, const MyString &other)
{
    out << other.str;
    return out;
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
int MyString::charInString(char sym) const
{
    int counter = 0;
    while (counter < size)
    {
        if (str[counter] == sym)
            return counter;
        else
            counter++;
    }
    return -1;
}
int MyString::subString(const char *subStr) const
{

    bool found = 0;
    for (int i = 0; i < size; i++)
    {
        int counter = 0;
        for (int j = 0; j < strlen(subStr); j++)
        {
            while (str[i + j] == subStr[j] && j < strlen(subStr))
            {
                // cout << "vliza za " << str[i + j] << " i " << subStr[j] << "     " << i << j <<endl;
                counter++;
                if (counter == strlen(subStr))
                {
                    return i;
                    found = true;
                }
                j++;
            }
        }
    }
    if (!found)
        return -1;
    //     while (counter < max(size, strlen(subStr)))
    //     {
    //         if (str[counter] == subStr[0])
    //         {
    //             for (int i = 0; i < strlen(subStr); i++)
    //             {
    //                 if (str[counter + i] != subStr[i])
    //                     found = 0;
    //             }
    //         }
    //         else
    //             counter++;
    //     }
    // return counter;
}
double MyString::strToDouble() const
{
    size_t leftPart = 0, rightPart = 0, leftPartCopy;
    double num = 0;
    if (charInString('.')==-1)
    {
        for (int i = 0; i < size; i++)
        {
            num += (str[i] - '0') * pow(10, size -1- i);
        }
    }
    else
    {
        while (str[leftPart] != '.')
            leftPart++;
        leftPartCopy = leftPart;
        size_t pointIndex = leftPart;
        leftPart++;
        while (str[leftPart] != '\0')
        {
            rightPart++;
            leftPart++;
        }
        for (int i = 0; i < leftPartCopy; i++)
        {
            num += (str[i] - '0') * pow(10, leftPartCopy - i - 1);
        }
        for (int i = 1; i < rightPart + 1; i++)
        {
            num += (str[i + pointIndex] - '0') * pow(0.1, i);
        }
    }
    return num;
}
double MyString::strToInt() const
{
    double num = 0;   
        for (int i = 0; i < size; i++)
        {
            num += (str[i] - '0') * pow(10, size - i);
        }
    return num;
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