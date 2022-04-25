#include <iostream>
#include <cstring>
#define MAX_SIZE 1024
using namespace std;
enum saberType
{
    SINGLEBLADED = 1,
    DOUBLE_BLADED,
    CROSSGUARD
};
struct LightSaber
{
    char *colour;
    saberType type;
};
struct Jedi
{
    char *name;
    unsigned int age;
    unsigned power;
    LightSaber lightSaber;
    double hp;
};
void initializeSaber(Jedi &jedi)
{
    char input[MAX_SIZE];
    cin >> input;
    jedi.lightSaber.colour = new char[strlen(input) + 1];
    strcpy(jedi.lightSaber.colour, input);
    int sabType;
    cout << "Enter the type of the lightsaber!\n ";
    cout << "1 = SINGLEBLADED\n";
    cout << "2 = DOUBLE_BLADED\n";
    cout << "3 = CROSSGUARD\n";
    cin >> sabType;
    switch (sabType)
    {
    case 1:
        jedi.lightSaber.type = SINGLEBLADED;
        break;
    case 2:
        jedi.lightSaber.type = DOUBLE_BLADED;
        break;
    case 3:
        jedi.lightSaber.type = CROSSGUARD;
        break;
    default:
        throw "That is not a correct type!";
        break;
    }
}
void initializeJedi(Jedi &jedi)
{
    char input[MAX_SIZE];
    cin >> input;
    jedi.name = new char[strlen(input) + 1];
    strcpy(jedi.name, input);
    cin >> jedi.age;
    cin >> jedi.power;
    initializeSaber(jedi);
    jedi.hp = 100;
}
void printSaber(LightSaber &saber)
{
    cout << saber.colour;
    switch (saber.type)
    {
    case 1:
        cout << SINGLEBLADED;
        break;
    case 2:
        cout << DOUBLE_BLADED;
        break;
    case 3:
        cout << CROSSGUARD;
        break;
    }
}
void printJedi(Jedi &jedi)
{
    cout << "Jedi: " << jedi.name << '\n';
    cout << "Age: " << jedi.age << '\n';
    cout << "Power: " << jedi.power << '\n';
    printSaber(jedi.lightSaber);
    cout << "HP: " << jedi.hp << '\n';
}
void killJedi(Jedi& jedi)
{
    delete[] jedi.name;
    delete[] jedi.lightSaber.colour;
}
void battle(Jedi &jedi1, Jedi &jedi2)
{
    int jedi1Dmg = (jedi1.power * jedi1.lightSaber.type * strlen(jedi1.lightSaber.colour))
     / jedi1.age;
    int jedi2Dmg = (jedi2.power * jedi2.lightSaber.type * strlen(jedi2.lightSaber.colour))
     / jedi2.age;
}
