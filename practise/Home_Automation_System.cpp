#include <iostream>
using namespace std;

class Light
{
protected:
    bool state = false;
    string color = "noColor";
    int intensity = 0;

public:
    void changeStateOfLight()
    {
        this->state = !state;
    }
    bool getStateOfLight()
    {
        return this->state;
    }
    void getAllAttributesOfLight()
    {
        cout << this->state << endl;
        cout << this->color << endl;
        cout << this->intensity << endl;
    }
    virtual void info() = 0;
};
class Door
{
protected:
    bool state = false;
    string material;
    bool autoLock;

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
    int fanSpeed;

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
    friend class SamsungLightBuilder;
};
class SamsungLightBuilder
{
private:
    SamsungLight *light;

public:
    SamsungLightBuilder(SamsungLight *l)
    {
        this->light = l;
    }
    SamsungLightBuilder &setColor(string c)
    {
        light->color = c;
        return *this;
    }
    SamsungLightBuilder &setIntensity(int i)
    {
        light->intensity = i;
        return *this;
    }
    SamsungLight *build()
    {
        return light;
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

class SamsungFactory : public SmartHomeFactory
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

class PhillipsFactory : public SmartHomeFactory
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
class RemoteControl
{
private:
    Command *lc;
    Command *dc;

public:
    void setLightCommand(Command *LightCommand)
    {
        this->lc = LightCommand;
    }
    void setDoorCommand(Command *DoorCommand)
    {
        this->dc = DoorCommand;
    }
    void pressLight()
    {
        lc->execute();
    }
    void pressDoor()
    {
        dc->execute();
    }
};

int main()
{
    SmartHomeFactory *shf = new SamsungFactory();
    Light *l1 = shf->createLight();
    // cout << l1->getStateOfLight() << endl;
    Command *lc = new ChangeLightStateCommand(l1);
    RemoteControl rc;
    rc.setLightCommand(lc);
    rc.pressLight();
    // cout << l1->getStateOfLight() << endl;
    rc.pressLight();
    // cout << l1->getStateOfLight() << endl;
    // SmartHomeFactory *shf = new PhillipsFactory();
    SamsungLight *sl = dynamic_cast<SamsungLight *>(l1);
    SamsungLightBuilder builder(sl);
    Light *modifiedL1 = builder
                            .setColor("BLUE")
                            .setIntensity(200)
                            .build();
    l1->getAllAttributesOfLight();
}