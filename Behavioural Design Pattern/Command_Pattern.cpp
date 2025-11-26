#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Command
{
public:
    virtual void execute() = 0;
};

class Light
{
private:
    bool state;

public:
    void changeStateOfLight()
    {
        this->state = !this->state;
    }
    bool getLightState()
    {
        return state;
    }
};

class Door
{
private:
    bool state;

public:
    void changeStateOfDoor()
    {
        this->state = !this->state;
    }
    bool getDoorState()
    {
        return state;
    }
};

class ChangeLightStateCommand : public Command
{
private:
    Light *light;

public:
    ChangeLightStateCommand(Light *light)
    {
        this->light = light;
    }
    void execute() override
    {
        light->changeStateOfLight();
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
    Command *LightCommand;
    Command *DoorCommand;

public:
    void setLightCommand(Command *LightCommand)
    {
        this->LightCommand = LightCommand;
    }
    void setDoorCommand(Command *DoorCommand)
    {
        this->DoorCommand = DoorCommand;
    }
    void pressLight()
    {
        LightCommand->execute();
    }
    void pressDoor()
    {
        DoorCommand->execute();
    }
};
int main()
{
    Light l;
    Door d;
    Command *c1 = new ChangeLightStateCommand(&l);
    Command *c2 = new ChangeDoorStateCommand(&d);
    RemoteControl *rc = new RemoteControl();
    rc->setLightCommand(c1);
    rc->pressLight();
}