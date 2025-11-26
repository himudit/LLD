#include <iostream>
using namespace std;

class Light
{
protected:
    bool state = false;
    string color;
    int intensity;

public:
    void on()
    {
        state = true;
    }
    void off()
    {
        state = false;
    }
    virtual void info() = 0;
};
class Door
{
protected:
    bool state = false;

public:
    virtual void info() = 0;
};
class AC
{
protected:
    bool state = false;
    int temp;
    bool powerSaving = false;

public:
    virtual void info() = 0;
};

class SamsungLight : public Light
{
public:
    void info() override
    {
        cout << "Samsung Light";
    }
};
class SamsungDoor : public Door
{
public:
    void info() override
    {
        cout << "Samsung Door";
    }
};
class SamsungAC : public AC
{
public:
    void info() override
    {
        cout << "Samsung AC";
    }
};

class PhillipLight : public Light
{
public:
    void info() override
    {
        cout << "Phillips Light";
    }
};
class PhillipDoor : public Door
{
public:
    void info() override
    {
        cout << "Phillips Door";
    }
};
class PhillipAC : public AC
{
public:
    void info() override
    {
        cout << "Phillips AC";
    }
};

class SmartHomeFactory
{
public:
    virtual Light *createLight() = 0;
    virtual Door *createDoor() = 0;
    virtual AC *createAC() = 0;
};

class SamsungFactory : SmartHomeFactory
{
public:
    Light *createLight()
    {
        return new SamsungLight;
    }

    Door *createDoor()
    {
        return new SamsungDoor;
    }

    AC *createAC()
    {
        return new SamsungAC;
    }
};

class PhillipsFactory : SmartHomeFactory
{
public:
    Light *createLight()
    {
        return new PhillipLight;
    }

    Door *createDoor()
    {
        return new PhillipDoor;
    }

    AC *createAC()
    {
        return new PhillipAC;
    }
};