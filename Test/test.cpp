
// ~
#include <iostream>
#include <cstring>
using namespace std;
class Word
{
private:
    int wordSize;
    char *str = NULL;
    void copyFrom(const Word &other)
    {
        wordSize = other.wordSize;
        str = new char[wordSize];
        for (int i = 0; i < wordSize; i++)
        {
            str[i] = other.str[i];
        }
        str[wordSize] = '\0';
    }
    void free()
    {
        delete str;
    }

public:
    Word()
    {
        wordSize = 0;
        str = NULL;
    }
    Word(const char *other)
    {
        wordSize = strlen(other);
        str = new char[wordSize];
        for (int i = 0; i < wordSize; i++)
        {
            str[i] = other[i];
        }
        str[wordSize] = '\0';
    }
    Word(const Word &other)
    {
        copyFrom(other);
    }
    Word &operator=(const Word &other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }
    char *getWord() const
    {
        return str;
    }
    int wordCompare(const Word &other) const
    {
        return strcmp(str, other.str);
    }
    ~Word()
    {
        free();
    }
};

int main()
{
    Word w1("kurva");
    Word w2("kurva");
    cout << w1.wordCompare(w2);
    return 0;
}