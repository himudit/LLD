#include <iostream>
using namespace std;

class Car
{
public:
    virtual void drive() = 0;
    virtual ~Car() {}
};

class Bike
{
public:
    virtual void ride() = 0;
    virtual ~Bike() {}
};

class ToyotaCar : public Car
{
public:
    void drive() override
    {
        cout << "Driving Toyota Car 🚗 (Toyota)" << endl;
    }
};

class ToyotaBike : public Bike
{
public:
    void ride() override
    {
        cout << "Riding Toyota Bike 🏍️ (Toyota)" << endl;
    }
};

class HondaCar : public Car
{
public:
    void drive() override
    {
        cout << "Driving Honda Car 🚗 (Honda)" << endl;
    }
};

class HondaBike : public Bike
{
public:
    void ride() override
    {
        cout << "Riding Honda Bike 🏍️ (Honda)" << endl;
    }
};

class VehicleFactory
{
public:
    virtual Car *createCar() = 0;
    virtual Bike *createBike() = 0;
    virtual ~VehicleFactory() {}
};
class ToyotaFactory : public VehicleFactory
{
public:
    Car *createCar() override { return new ToyotaCar(); }
    Bike *createBike() override { return new ToyotaBike(); }
};
class HondaFactory : public VehicleFactory
{
public:
    Car *createCar() override { return new HondaCar(); }
    Bike *createBike() override { return new HondaBike(); }
};
int main()
{
    VehicleFactory *factory;
    factory = new ToyotaFactory();

    Car *c1 = factory->createCar();
    c1->drive();

    factory = new HondaFactory();

    Bike *b1 = factory->createBike();
    b1->ride();
}

// abstract factory is factory pattern plus one more dimension of complexity. Abstract factory handles two axes - which type AND which family/brand And yes — the goal is to remove if-else and follow open-closed principle.