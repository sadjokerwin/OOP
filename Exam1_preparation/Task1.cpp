#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#define MAX_SIZE 1024
class Item
{
private:
    char *name;
    double price;
    void copyFrom(const Item &other)
    {
        price = other.price;
        int size = strlen(other.name);
        name = new char[size];
        strcpy(name, other.name);
    }
    void free()
    {
        delete name;
    }

public:
    Item()
    {
        name = NULL;
        price = 0;
    }
    Item(const double price, char *word)
    {
        setName(word);
        setPrice(price);
    }
    Item(const Item &other)
    {
        copyFrom(other);
    }
    Item &operator=(const Item &other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }
    bool operator==(const Item &other)
    {
        return (strcmp(name, other.name) == 0) && (price == other.price);
    }
    void setPrice(const double price)
    {
        this->price = price;
    }
    void setName(char *word)
    {
        name = word;
    }
    double getPrice() const
    {
        return price;
    }
    char *getName() const
    {
        return name;
    }
};
class Shop
{
private:
    Item *stock = new Item[numOfItems];
    int numOfItems;
    void copyFrom(const Shop &other)
    {
        numOfItems = other.numOfItems;
        stock = new Item[numOfItems];
        for (int i = 0; i < numOfItems; i++)
        {
            stock[i] = other.stock[i];
        }
    }
    void free()
    {
        delete stock;
    }
public:
    Shop()
    {
        numOfItems = 0;
    }
    Shop(const int num, const Shop &other)
    {
        copyFrom(other);
    }
    int getNumOfItems() const
    {
        return numOfItems;
    }
    Shop &operator=(const Shop &other)
    {
        if(this!=&other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }
    void addItem(const Item &other)
    {
        stock[numOfItems] = other;
        numOfItems++;
    }
    bool findItem(const Item &other)
    {
        for (int i = 0; i < numOfItems; i++)
        {
            if (stock[i] == other)
                return true;
        }
        return false;
    }
    void saveToFile(const char *fileName)
    {
        ofstream file(fileName);
        for (int i = 0; i < numOfItems; i++)
        {
            file << stock[i].getName() << " " << stock[i].getPrice() << '\n';
        }
    }
    ~Shop()
    {
        free();
    }
};
int main()
{
    Item i_1(2.5, "Haivan");
    Item i_2(3.5, "Ran4o");
    Item i_3(3.5, "paran");
    Shop s1;
    s1.addItem(i_1);
    s1.addItem(i_2);
    s1.saveToFile("kurva.txt");
}
