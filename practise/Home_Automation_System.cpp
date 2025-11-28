#include <iostream>
using namespace std;

class Light
{
protected:
    bool state = false;
    string color;
    int intensity;

public:
    void changeStateOfLight()
    {
        this->state = !state;
    }
    virtual void info() = 0;
};
class Door
{
protected:
    bool state = false;

public:
    void changeStateOfDoor()
    {
        this->state = !state;
    }
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

class Command
{
public:
    virtual void execute() = 0;
};
class ChangeLightStateCommand : public Command
{
private:
    Light *l;

public:
    ChangeLightStateCommand(Light *light)
    {
        this->l = light;
    }
    void execute()
    {
        this->l->changeStateOfLight();
    }
};
class ChangeDoorStateCommand : public Command
{
private:
    Door *door;

public:
    ChangeDoorStateCommand(Door *door)
    {
        this->door = door;
    }

    void execute() override
    {
        door->changeStateOfDoor();
    }
};