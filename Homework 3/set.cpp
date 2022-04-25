#include "set.h"
void Set::copyFrom(const Set &other)
{
    numOfWords = other.numOfWords;
    words = new Word[numOfWords];
    for (int i = 0; i < numOfWords; i++)
    {
        words[i] = other.words[i];
    }
}
void Set::free()
{
    delete words;
}
void Set::sortArray()
{
    for (int j = 0; j < numOfWords; j++)
    {
        for (int k = j; k < numOfWords; k++)
        {
            if (words[j].wordCompare(words[k]) > 0)
                swap(words[j], words[k]);
        }
    }
    isSorted = true;
}
void Set::expandSet()
{
    arraySize *= 2;
    Word *wordsCpy = new Word[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        if (wordsCpy[i].wordCompare(words[i]) != 0)
            wordsCpy[i] = words[i];
    }

    words = wordsCpy;
}
void Set::combineSets(const Set &other, int firstSetNum)
{
    for (int i = firstSetNum; i < firstSetNum + other.numOfWords; i++)
    {
        for (int k = 0; k < i; k++)
            if ((*this)[other.words[k]] != 0)
            {
                words[i] = other.words[i];
                numOfWords++;
            }
    }
}
int Set::lookForInSet(const Word &word) const
{
    for (int i = 0; i < numOfWords; i++)
    {
        if (words[i].wordCompare(word) == 0)
            return i;
    }
}
Set::Set()
{
    numOfWords = 0;
    words = NULL;
}
Set::~Set()
{
    free();
}
Set::Set(const Set &other)
{
    copyFrom(other);
}
Set &Set::operator=(const Set &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
Set &Set::operator+=(const Set &other)
{
    while ((numOfWords + other.numOfWords) > (arraySize * 2))
    {
        expandSet();
    }
    combineSets(other, numOfWords);
    return *this;
}
Set &Set::operator-=(const Set &other)
{
    int index;
    for (int i = 0; i < other.numOfWords; i++)
    {
        index = lookForInSet(other.words[i]);
        if (index >= 0 && index < numOfWords)
        {
            words[index].setWord(NULL);
            numOfWords--;
        }
    }
    sortArray();
}
Set &Set::operator*=(const char *a)
{
    if ((*this)[a] != 0)
    {
        if (numOfWords + 1 > arraySize)
            expandSet();
    }
}
Set &Set::operator/=(const char *a)
{
    int index = 0;
    for (int i = 0; i < numOfWords; i++)
    {
        index = lookForInSet(words[i]);
        if (index >= 0 && index < numOfWords)
        {
            words[index].setWord(NULL);
            numOfWords--;
        }
    }
}
bool Set::operator[](const char *word)
{
    if (isSorted == 0)
    {
        sortArray();
    }
    for (int i = 0; i < numOfWords; i++)
    {
        if (binarySearch(this, i, numOfWords, word) == 1)
            return 1;
    }
    return 0;
}
bool Set::operator[](const Word &other)
{
    if (isSorted == 0)
    {
        sortArray();
    }
    for (int i = 0; i < numOfWords; i++)
    {
        if (binarySearch(this, i, numOfWords, other) == 1)
            return 1;
    }
    return 0;
}
int Set::getNums()
{
    return numOfWords;
}
std::ostream &operator<<(std::ostream &out, const Set &set)
{
    for (int i = 0; i < set.numOfWords; i++)
    {
        out << set.words[i] << endl;
    }
    return out;
}
std::istream &operator>>(std::istream &in, Set &set)
{
    for (int i = 0; i < set.numOfWords; i++)
    {
        in >> set.words[i];
    }
    return in;
}
Set operator+(const Set &lhs, const Set &rhs)
{
    Set copy(lhs);
    copy += rhs;
    return copy;
}
Set operator-(const Set &lhs, const Set &rhs)
{
    Set copy(lhs);
    copy -= rhs;
    return copy;
}
bool Set::binarySearch(const Set *set, int left, int right, const Word &other)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (words[mid].wordCompare(other) == 0)
            return true;
        if (words[mid].wordCompare(other) == -1)
            return binarySearch(set, left, mid - 1, other);

        return binarySearch(set, mid + 1, right, other);
    }
    return false;
}