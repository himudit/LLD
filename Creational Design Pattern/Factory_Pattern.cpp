#include <iostream>
#include <memory>
using namespace std;

class Vehicle
{
public:
    virtual void drive() = 0;
    virtual ~Vehicle() {}
};
class Car : public Vehicle
{
public:
    void drive() override
    {
        cout << "Driving a Car 🚗" << endl;
    }
};

class Bus : public Vehicle
{
public:
    void drive() override
    {
        cout << "Driving a Bus 🚌" << endl;
    }
};
class VehicleFactory
{
public:
    static Vehicle *createVehicle(const string &type)
    {
        if (type == "car")
            return new Car();
        if (type == "bus")
            return new Bus();
        return nullptr;
    }
};
int main()
{
    Vehicle *v1 = VehicleFactory::createVehicle("car");
    v1->drive();

    Vehicle *v2 = VehicleFactory::createVehicle("bus");
    v2->drive();

    // IMPORTANT: free memory
    delete v1;
    delete v2;

    return 0;
}