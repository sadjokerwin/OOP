#include "word.h"
void Word::copyFrom(const Word &other)
{
    wordSize = other.wordSize;
    str = new char[wordSize];
    strcpy(str, other.str);
}
void Word::free()
{
    delete str;
}
Word::Word()
{
    wordSize = 0;
    str = NULL;
}
Word::Word(const char *other)
{
    wordSize = strlen(other);
    str = new char[wordSize];
    strcpy(str, other);
}
Word::Word(const Word &other)
{
    copyFrom(other);
}
Word &Word::operator=(const Word &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
char *Word::getWord()
{
    return str;
}
void Word::setWord(char *word)
{
    str = word;
}
int Word::wordCompare(const Word &other) const
{
    return strcmp(str, other.str);
}
int Word::wordCompare(const char *word) const
{
    return strcmp(str, word);
}
std::ostream &operator<<(std::ostream &out, const Word &word)
{
    out << word.str;
    return out;
}
std::istream &operator>>(std::istream &in, Word &word)
{
        in >> word.str;
    return in;
}
Word::~Word()
{
    free();
}