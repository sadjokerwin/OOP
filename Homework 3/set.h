#pragma once
#include <iostream>
#include "word.h"
#include <cstring>
using namespace std;

class Set
{
private:
    int numOfWords;
    int arraySize;
    bool isSorted;
    Word *words;
    void copyFrom(const Set &other);
    void free();
    void sortArray();
    void expandSet();
    void combineSets(const Set &other, int firstSetNum);
    int lookForInSet(const Word &word) const;
    bool binarySearch(const Set *set, int l, int r, const Word &other);

public:
    Set();
    Set(const Set &other);
    Set &operator=(const Set &other);
    Set &operator+=(const Set &other);
    Set &operator-=(const Set &other);
    Set &operator*=(const char* a);
    Set &operator/=(const char* a);
    bool operator[](const char* word);
    bool operator[](const Word &other);
    int getNums();
    friend std::ostream &operator<<(std::ostream &out, const Set &set);
    friend std::istream &operator>>(std::istream &in, Set &set);
    ~Set();
};

Set operator+(const Set &other);
Set operator-(const Set &other);