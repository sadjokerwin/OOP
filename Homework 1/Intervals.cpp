#include <iostream>
using namespace std;
bool isPrimeNumber(int a)
{
    for (int i = 2; i <= (a / 2); i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
bool isPalindrom(int a)
{
    int n;
    int digit = 0;
    int rev = 0;
    n = a;
    do
    {
        digit = a % 10;
        rev = (rev * 10) + digit;
        a = a / 10;
    } while (a != 0);
    return n == rev;
}
bool hasUniqDec(int a)
{
    int n = a;
    int counter = 0;
    int num[1024];
    while (n > 0)
    {
        num[counter] = n % 10;
        n /= 10;
        counter++;
    }
    for (int i = 0; i < counter; i++)
    {
        for (int j = i + 1; j < counter; j++)
        {
            if (num[i] == num[j])
                return false;
        }
    }
    return true;
}
bool isNum2Power(int a)
{

    if (a == 1)
    {
        return false;
    }
    while (a > 1)
    {
        if (a % 2 != 0)
        {
            return false;
        }
        a /= 2;
    }
    return true;
}
class Interval
{
    int limitL;
    int limitR;
    void isValidInterval()
    {
        if (!(limitL < limitR))
        {
            limitL = 0;
            limitR = 0;
        }
    }
public:
    Interval()
    {
        limitL = 0;
        limitR = 0;
    }
    Interval(int a, int b)
    {
        setInterval(a, b);
    }
    void setInterval(int a, int b)
    {
        limitL = a;
        limitR = b;
        isValidInterval();
    }
    void setLeftLimit(int a)
    {
        limitL = a;
        isValidInterval();
    }
    void setRightLimit(int b)
    {
        limitR = b;
        isValidInterval();
    }
    int getLeftLimit() const
    {
        return limitL;
    }
    int getRightLimit() const
    {
        return limitR;
    }
    int intervalLen() const
    {
        return limitL - limitR;
    }
    bool isNumInInterval(int a) const
    {
        int length = intervalLen();
        cout << limitL;
        for (int i = limitL; i <= limitR; i++)
        {
            if (a == i)
                return true;
        }
        return false;
    }
    void primeNumsInInterval() const
    {
        int counter = 0;
        for (int i = limitL; i <= limitR; i++)
        {
            if (isPrimeNumber(i))
                counter++;
        }
        cout<<counter;
    }
    int palindromNumsInInterval() const
    {
        int counter = 0;
        for (int i = limitL; i <= limitR; i++)
        {
            if (isPalindrom(i))
                counter++;
        }
        return counter;
    }
    int numsWithUniqDec() const
    {
        int counter = 0;
        for (int i = limitL; i <= limitR; i++)
        {
            if (hasUniqDec(i))
                counter++;
        }
        return counter;
    }
    bool limits2Power() const
    {
        return isNum2Power(limitL) && isNum2Power(limitR);
    }
    Interval intersect(const Interval& other) const
    {
        Interval result;
        if (limitR > other.limitL)
        {
            result.limitL = other.limitL;
            result.limitR = limitR;
            return result;
        }
        else
        {
            cout << "The intersection is the empty set"; // Не беше написано какво трябва да изкарва при празно сечение
        }
    }
    Interval uniting(const Interval &other) const
    {
        Interval result;
        if (limitR > other.limitL)
        {
            result.limitL = limitL;
            result.limitR = other.limitR;
        }
        else
        {
            result.limitL = 0;
            result.limitR = 0;
        }
        return result;
    }
    bool isSuperInterval(const Interval &other) const
    {
        return (other.limitL >= limitL) && (other.limitR <= limitR);
    }
    void print() const
    {
        cout << '[' << limitL << ' ' << limitR << ']' << endl;
    }
};
int main()
{
    Interval t1(3, 10); // [3, 10]
    Interval t2(4, 14); // [4, 14]
    Interval t3;        // [0, 0]

    Interval result = t1.intersect(t2); // [4, 10]
    t2.isSuperInterval(result); // true

    result.primeNumsInInterval(); // 2 (only 5 and 7)
}