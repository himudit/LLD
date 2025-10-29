#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

// Open-Closed Principle
class Shape
{
public:
    virtual double area() = 0;
};

class Rectangle : public Shape
{
    double w, h;

public:
    Rectangle(double width, double height)
    {
        w = width;
        h = height;
    }
    double area()
    {
        return w * h;
    }
};

int main()
{
    Rectangle rect(4, 5);
    cout << rect.area();
}

// Factory Design Pattern
// what is static
// what is ::
class Vehicle
{
public:
    virtual void printType() = 0;
    virtual ~Vehicle() {}
};
class Car : public Vehicle
{
public:
    void printType() override
    {
        cout << "This is a Car" << endl;
    }
};
class vehicleFactory
{
public:
    static Vehicle *getVehicle(string v)
    {
        if (v == "car")
        {
            return new Car();
        }
        return nullptr;
    }
};
int main()
{
    Vehicle *v1 = vehicleFactory::getVehicle("car");
    v1->printType();
}

// Abstract Factory Pattern
// Manage Different Car Brands
// class Vehicle
// {
// public:
//     virtual void printType() = 0;
//     virtual ~Vehicle() {}
// };
// class Honda : public Vehicle
// {
// public:
//     void printType() override
//     {
//         cout << "I am of Honda Type";
//     }
// };
// class vehicleFactory
// {
// public:
//     virtual Vehicle* createVehicle() = 0;
// };
// class HondaFactory : public vehicleFactory
// {
// public:
//     Vehicle* createVehicle() override
//     {
//         return new Honda();
//     }
// };
// int main(){
//     vehicleFactory* factory = new HondaFactory();
//     Vehicle* honda = factory->createVehicle();
// }

// Builder Design Pattern
// Used to make custom object
// Traditional Method use Constructor Overloading
// class Car
// {
// private:
//     string engine;
//     int seats;
//     Car(const string &engine, int seats)
//     {
//         this->engine = engine;
//         this->seats = seats;
//     }

// public:
//     string getEngine()
//     {
//         return engine;
//     }
//     int getSeats()
//     {
//         return seats;
//     }

// public:
//     class CarBuilder
//     {
//     private:
//         string engine;
//         int seats;
//     public:
//         CarBuilder &setEngine(const string &engine)
//         {
//             this->engine = engine;
//             return *this;
//         }
//         Car build()
//         {
//             return Car(engine, seats);
//         }
//     };
// };

// int main(){
//     Car myCar = Car::CarBuilder().setEngine("V8").build();
// }

// Singleton Design Pattern
class Logger
{
private:
    static Logger *instance;
    Logger()
    {
        // cout
    }

public:
    static Logger *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Logger();
        }
        return instance;
    }
    void log(string message)
    {
        cout << "Log: " << message << endl;
    }
};
int main()
{
    Logger *log1 = Logger::getInstance();
    log1->log("ejee");
}