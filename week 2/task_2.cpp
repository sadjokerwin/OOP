#include <iostream>
#include <fstream>
#define BUFF 1024
using namespace std;
int main()
{
    ifstream file("myFile.txt");
    while(!file.eof())
    {
        char buff[BUFF];
        file.getline(buff, BUFF);
        cout << buff << '\n';
    }
    file.close();
    /*ofstream file("myFile.txt");

    if (!file.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }
    int a = 3;
    int b = 10;

    file << a << " " << b << " " << a + b << endl;

    if (!file.eof()) //check if the file has ended
        cout << "The file contains more data after the two integers!" << endl;

    file.close();*/
}