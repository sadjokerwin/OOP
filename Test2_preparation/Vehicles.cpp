#include <iostream>
#include <cstring>
using namespace std;
class Vehicle
{
protected:
    char *mMake;
    size_t mMaxSpeed;
    size_t mMaxSpeed2ndClass;
    size_t mMaxSpeed3rdClass;

public:
    Vehicle()
    {
        mMake = nullptr;
        mMaxSpeed = 0;
        mMaxSpeed2ndClass = 0;
        mMaxSpeed3rdClass = 0;
        cout << "default constr" << endl;
    }
    void setMake(const char *make)
    {
        mMake = new char[strlen(make) + 1];
        strcpy(mMake, make);
    }
    virtual void setMaxSpeed(size_t maxSpeed) = 0;
    virtual double calculateTime(size_t distanceHighway, size_t distance2ndClass, size_t distance3rdClass) const = 0;
    virtual char *getMake() const = 0;
    size_t getMaxSpeed() const
    {
        return mMaxSpeed;
    }
    size_t getMaxSpeed2ndClass() const
    {
        return mMaxSpeed2ndClass;
    }
    size_t getMaxSpeed3rdClass() const
    {
        return mMaxSpeed3rdClass;
    }
};
class Car : public Vehicle
{
public:
    Car(const char *make, size_t maxspeed)
    {
        setMake(make);
        setMaxSpeed(maxspeed);
    }
    double calculateTime(size_t distanceHighway, size_t distance2ndClass, size_t distance3rdClass) const
    {
        return ((double)distanceHighway / mMaxSpeed) + ((double)distance2ndClass / mMaxSpeed2ndClass) + ((double)distance3rdClass / mMaxSpeed3rdClass);
    }
    char *getMake() const
    {
        return mMake;
    }
    void setMaxSpeed(size_t maxSpeed)
    {
        if (maxSpeed >= 180 && maxSpeed <= 240)
        {
            mMaxSpeed = maxSpeed;
            mMaxSpeed2ndClass = mMaxSpeed;
            mMaxSpeed3rdClass = mMaxSpeed;
        }
        else
        {
            mMaxSpeed = 180;
            mMaxSpeed2ndClass = mMaxSpeed;
            mMaxSpeed3rdClass = mMaxSpeed;
        }
    }
};
class Minivan : public Vehicle
{
public:
    Minivan(const char *make, size_t maxspeed)
    {
        setMake(make);
        setMaxSpeed(maxspeed);
    }
    double calculateTime(size_t distanceHighway, size_t distance2ndClass, size_t distance3rdClass) const
    {
        return ((double)distanceHighway / mMaxSpeed) + ((double)distance2ndClass / mMaxSpeed2ndClass) + ((double)distance3rdClass / mMaxSpeed3rdClass);
    }
    char *getMake() const
    {
        return mMake;
    }
    void setMaxSpeed(size_t maxSpeed)
    {
        if (maxSpeed >= 120 && maxSpeed <= 160)
        {
            mMaxSpeed = maxSpeed;
            mMaxSpeed2ndClass = mMaxSpeed / 2;
            mMaxSpeed3rdClass = mMaxSpeed / 3;
        }
        else
        {
            mMaxSpeed = 120;
            mMaxSpeed2ndClass = mMaxSpeed / 2;
            mMaxSpeed3rdClass = mMaxSpeed / 3;
        }
    }
};
class Truck : public Vehicle
{
public:
    Truck(const char *make, size_t maxspeed)
    {
        setMake(make);
        setMaxSpeed(maxspeed);
    }
    double calculateTime(size_t distanceHighway, size_t distance2ndClass, size_t distance3rdClass) const
    {
        return ((double)distanceHighway / mMaxSpeed) + ((double)distance2ndClass / mMaxSpeed2ndClass) + ((double)distance3rdClass / mMaxSpeed3rdClass);
    }
    char *getMake() const
    {
        return mMake;
    }
    void setMaxSpeed(size_t maxSpeed)
    {
        if (maxSpeed >= 80 && maxSpeed <= 140)
        {
            mMaxSpeed = maxSpeed / 2;
            mMaxSpeed2ndClass = mMaxSpeed / 4;
            mMaxSpeed3rdClass = 10;
        }
        else
        {
            mMaxSpeed = 80;
            mMaxSpeed2ndClass = mMaxSpeed / 4;
            mMaxSpeed3rdClass = 10;
        }
    }
};
class Garage
{
private:
    Vehicle **mGarage;
    size_t numOfVehicles;
    size_t mCapacity;

public:
    Garage()
    {
        mCapacity = 16;
        mGarage = new Vehicle *[mCapacity];
        numOfVehicles = 0;
    }
    void addVehicle(const char *make, size_t maxspeed)
    {
        if (numOfVehicles + 1 < mCapacity)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case 'c':
                mGarage[numOfVehicles] = new Car(make, maxspeed);
                numOfVehicles++;
                break;
            case 'm':
                mGarage[numOfVehicles] = new Minivan(make, maxspeed);
                numOfVehicles++;
                break;
            case 't':
                mGarage[numOfVehicles] = new Truck(make, maxspeed);
                numOfVehicles++;
                break;
            default:
                break;
            }
        }
    }
    void eligibleVehicles(size_t distanceHighway, size_t distance2ndClass, size_t distance3rdClass, size_t time) const
    {
        for (int i = 0; i < mCapacity; i++)
        {
            if (mGarage[i]->calculateTime(distanceHighway, distance2ndClass, distance3rdClass) <= time)
            {
                cout << mGarage[i]->getMake();
            }
        }
    }
    Vehicle **getGarage() const
    {
        return mGarage;
    }
};
int main()
{
    // Car c1("Audi", 195);
    // Car c2("Toyota", 180);
    // Car c3("BMW", 230);

    Garage g;
    g.addVehicle("Audi", 195);
    g.addVehicle("Toyota", 180);
    g.addVehicle("BMW", 230);
    g.eligibleVehicles(200, 100, 50, 2);
    return 0;
}