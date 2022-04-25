#include "word.h"
void Word::copyFrom(const Word &other)
{
    wordSize = other.wordSize;
    str = new char[wordSize];
    for (int i = 0; i < wordSize; i++)
    {
        str[i] = other.str[i];
    }
    str[wordSize] = '\0';
}
char* Word::getWord() const
{
    return str;
}
int Word::wordCompare(const Word &other) const
{
    return strcmp(str, other.str);
}
void Word::free()
{
    delete str;
}
Word::Word()
{
    wordSize = 0;
    // str = NULL;
}
Word::Word(const char *other)
{
    wordSize = strlen(other);
    str = new char[wordSize];
    for (int i = 0; i < wordSize; i++)
    {
        str[i] = other[i];
    }
    str[wordSize] = '\0';
}
Word::Word(const Word &other)
{
    copyFrom(other);
}
Word& Word::operator=(const Word &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
        
    }
    return *this;
}
Word::~Word()
{
    free();
}