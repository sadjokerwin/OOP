#include <iostream>
#include <fstream>
#include <cstring>
#define MAX_SIZE 1024
using namespace std;
char *hexConv(int a)
{
    int numResult[MAX_SIZE];
    int counter = 0;
    while (a > 0)
    {
        numResult[counter] = a % 16;
        a = a / 16;
        counter++;
    }
    char *result = new char[counter];
    int counter1 = counter - 1;
    for (int i = 0; i < counter; i++)
    {
        if (numResult[i] >= 0 && numResult[i] <= 9)
        {
            result[counter1] = (char)(numResult[i] + 48);
        }
        else
        {
            result[counter1] = (char)(numResult[i] + 55);
        }

        counter1--;
    }
    result[counter] = '\0';
    return result;
}
void write(const char *source, int data)
{
    ofstream f(source, ios::binary | ios::trunc);
    if (!f.is_open())
        cout << "File opening error!";
    else
    {
        f.write((const char *)&data, sizeof(data));
        f.close();
    }
}
char *read(const char *source, int len)
{
    ifstream f(source, ios::binary);
    if (!f.is_open())
        cout << "File opening error!";
    else
    {
        char *str = new char[len + 1];
        f.read(str, len);
        f.close();
        str[len] = '\0';
        return str;
    }
}
void view(const char *str, int len)
{
    int currSym;
    // char kur = '';
    for (int i = 0; i < len; i++)
    {
        currSym = str[i];
        // cout << currSym;
        if (currSym == 0)
            cout << "00";
        cout << hexConv(currSym) << ' ';
    }
    cout << endl;
    char currSym1;
    for (int i = 0; i < len; i++)
    {
        currSym1 = str[i];
        // cout << currSym1;
        if ((currSym1 >= 65 && currSym1 <= 90) || (currSym1 >= 97 && currSym1 <= 122))
            cout << (char)currSym1 << ' ' << ' ';
        else
            cout << "." << ' ' << ' ';
    }
}
void change(char *str, int len, int index, char newSym)
{
    str[index] = newSym;
}
void remove(char *&str, int &len)
{
    str[len - 1] = '\0';
    len--;
}
void add(char *&str, int &len, char newSym)
{
    char *newStr = new char[len + 1];
    strcpy(newStr, str);
    newStr[len] = newSym;
    str = newStr;
    delete[] newStr;
    len++;
}
void save(char *destination, char *content, int strlen)
{
    ofstream f(destination, ios::binary | std::ios::trunc);
    if (!f.is_open())
        cout << "File opening error!";
    else
    {
        f.write(content, strlen);
        f.close();
    }
}
void saveAs(char *content, int strlen)
{
    char destination[MAX_SIZE];
    cout << "Enter the name of the file where you would like to save as: " << endl;
    cin >> destination;
    ofstream f(destination, ios::binary | std::ios::trunc);
    if (!f.is_open())
        cout << "File opening error!";
    else
    {
        f.write(content, strlen);
        f.close();
        cout << "File has been saved successfully!";
    }
}
int main()
{
    int x = 25409;
    // hexConv(60000);
    //  cout << "Enter the data you want to write:" << endl;
    //  cin>>x;
    int strlength = sizeof(x);
    char *source = new char[MAX_SIZE];
    cin >> source;
    write(source, x);
    //read(source, strlength);
    char *content = new char[strlength + 1];
    strcpy(content, read(source, strlength));
    cout << content << endl;
    view(content, strlength);
    // remove(content, strlength);
    // view(content, strlength);
    // add(content, strlength, 'c');
    // view(content, strlength);
    // // save(source, content, strlength);
    // saveAs(content, strlength);
    delete[] source;
    delete[] content;
}