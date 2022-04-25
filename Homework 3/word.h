#ifndef __WORD_H
#define __WORD_H
// ~
#include <iostream>
#include <cstring>
using namespace std;
class Word
{
private:
    int wordSize;
    char *str;
    void copyFrom(const Word &other);
    void free();

public:
    Word();
    Word(const char *other);
    Word(const Word &other);
    Word &operator=(const Word &other);
    char *getWord();
    void setWord(char *word);
    int wordCompare(const Word &other) const;
    int wordCompare(const char* word) const;
    friend std::ostream &operator<<(std::ostream &out, const Word &word);
    friend std::istream &operator>>(std::istream &in, Word &word);
    ~Word();
};
#endif