#include <bits/stdc++.h>
using namespace std;

enum class VehicleType
{
    BIKE,
    CAR
};
class ParkingLot
{
    vector<ParkingSpot> bikeSpots;
    vector<ParkingSpot> carSpots;

public:
    ParkingLot(int bikeCount, int carCount)
    {
        for (int i = 0; i < bikeCount; i++)
            bikeSpots.push_back(ParkingSpot(VehicleType::BIKE));

        for (int i = 0; i < carCount; i++)
            carSpots.push_back(ParkingSpot(VehicleType::CAR));
    }
};

class ParkingSpot
{
public:
    VehicleType type;
    bool isFree;
    ParkingSpot(VehicleType t)
    {
        this->type = t;
        this->isFree = true;
    }
};

class BikeParkingSpot : public ParkingSpot
{
public:
    // BikeParkingSpot() : ParkingSpot() {};
};

class CarParkingSpot : public ParkingSpot
{
public:
    // CarParkingSpot() : ParkingSpot("Car") {};
};

class Vehicle
{
protected:
    VehicleType type;

public:
    Vehicle(VehicleType t) : type(t) {}
    virtual ~Vehicle() {}

    VehicleType getType() const
    {
        return type;
    }

    virtual string getInfo() const = 0; // for debugging
};
class Bike : public Vehicle
{
public:
    Bike() : Vehicle(VehicleType::BIKE) {}

    string getInfo() const override
    {
        return "Bike";
    }
};
class Car : public Vehicle
{
public:
    Car() : Vehicle(VehicleType::CAR) {}

    string getInfo() const override
    {
        return "Car";
    }
};
class VehicleFactory
{
public:
    static Vehicle *createVehicle(VehicleType type)
    {
        switch (type)
        {
        case VehicleType::BIKE:
            return new Bike();
        case VehicleType::CAR:
            return new Car();
        default:
            return nullptr;
        }
    }
};

class ParkingManager
{
public:
    virtual int findSpace() = 0;
    virtual void parkVehicle(Vehicle *v) = 0;
    virtual void removeVehicle(Vehicle *v) = 0;
};
class BikeParkingManager : public ParkingManager
{
public:
    int findSpace()
    {
    }
};

int main()
{
}