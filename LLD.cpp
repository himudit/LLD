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

// int main()
// {
//     Rectangle rect(4, 5);
//     cout << rect.area();
// }

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
// int main()
// {
//     Vehicle *v1 = vehicleFactory::getVehicle("car");
//     v1->printType();
// }

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
// class Logger
// {
// private:
//     static Logger *instance;
//     Logger()
//     {
//         // cout
//     }

// public:
//     static Logger *getInstance()
//     {
//         if (instance == nullptr)
//         {
//             instance = new Logger();
//         }
//         return instance;
//     }
//     void log(string message)
//     {
//         cout << "Log: " << message << endl;
//     }
// };
// int main()
// {
//     Logger *log1 = Logger::getInstance();
//     log1->log("ejee");
// }

// Notification System Practise
// class Notification
// {
// protected:
//     string messages;

// public:
//     Notification() = default;
//     Notification(const string m)
//     {
//         this->messages = m;
//     }

//     string getMessage()
//     {
//         return this->messages;
//     }
//     void setMessage(const string m)
//     {
//         this->messages = m;
//     }

//     virtual ~Notification() = default;
// };

// class Email : public Notification
// {
// public:
//     Email() = default;
//     Email(const string messages) : Notification(messages) {}
//     class Builder
//     {
//     private:
//         string recipient;
//         string messages;
//         string senderName;

//     public:
//         Builder setRecipient(string r)
//         {
//             this->recipient = r;
//             return *this;
//         }

//         Builder setMessage(string m)
//         {
//             this->messages = m;
//             return *this;
//         }

//         Builder setSenderName(string sN)
//         {
//             this->senderName = sN;
//             return *this;
//         }
//         Notification *build()
//         {
//             Email *e = new Email();
//             e->setMessage(this->messages);
//             return e;
//         }
//     };
// };

// class SMS : public Notification
// {

// public:
//     SMS() = default;
// };

// class NotificationFactory
// {
// public:
//     virtual Notification *getNotificationUsingType(const string &message, const string &recipient) = 0;
// };

// class EmailFactory : public NotificationFactory
// {
// public:
//     Notification *getNotificationUsingType(const string &message, const string &recipient) override
//     {
//         return Email::Builder()
//             .setMessage("ee")
//             .setRecipient("eje")
//             .build();
//     }
// };

// int main()
// {
//     NotificationFactory *factory = new EmailFactory();
//     Notification *n = factory->getNotificationUsingType("Hello!", "abc@gmail.com");
//     n->setMessage("Hi, how are you!!");
// }

// Strategy Pattern
// class PaymentStrategy
// {
// public:
//     virtual void processPayment(double amount) = 0;
//     virtual ~PaymentStrategy() = default;
// };
// class CreditCard : public PaymentStrategy
// {
// public:
//     void processPayment(double amount) override
//     {
//         cout << "Paid " << amount << " using Credit Card\n";
//     }
// };
// class PayPal : public PaymentStrategy
// {
// public:
//     void processPayment(double amount) override
//     {
//         cout << "Paid " << amount << " using PayPal\n";
//     }
// };
// class PaymentProcessor
// {
// private:
//     PaymentStrategy *strategy;

// public:
//     PaymentProcessor(PaymentStrategy *s) : strategy(s) {}
//     void process(double amount)
//     {
//         strategy->processPayment(amount);
//     }
// };
// int main()
// {
//     CreditCard credit;
//     PayPal paypal;

//     PaymentProcessor processor1(&credit);
//     processor1.process(100.0);
// }

// Ride-Sharing System Practise
// Users can book rides of different types (Bike, Mini, SUV).✅ (check for availability)
// Different payment methods (UPI, Card, Wallet) are supported.✅
// You can have different app themes/brands (Uber vs Ola).
// Riders get live fare updates based on traffic (observers).
class RideVehicle
{
protected:
    string vehicleName;
    string vehicleNumber;

public:
    RideVehicle(const string &name, const string &number)
        : vehicleName(name), vehicleNumber(number) {}
    string getVehicleName()
    {
        return this->vehicleName;
    }
};
class Bike : public RideVehicle
{
public:
    Bike(const string &name, const string &number) : RideVehicle(name, number) {}
};
class Mini : public RideVehicle
{
public:
    Mini(const string &name, const string &number) : RideVehicle(name, number) {}
};
class Rider
{
private:
    string name;
    string number;
    RideVehicle *vehicle;
public:
    Rider(const string &name, const string &number, RideVehicle *v)
    {
        this->name = name;
        this->number = number;
        this->vehicle = v;
    }
    string getName()
    {
        return this->name;
    }
    RideVehicle *getVehicle()
    {
        return vehicle;
    }
};
class User
{
private:
    string name;
    string number;

public:
    User(const string &name, const string &number)
    {
        this->name = name;
        this->number = number;
    }
    string getName()
    {
        return this->name;
    }
};
class Booking
{
private:
    User *user;           // who booked
    Rider *rider;         // who is driving
    RideVehicle *vehicle; // what vehicle
    string bookingType;   // "Bike", "Mini", etc.
    string bookingId;     // unique ID
    double fare;          // cost of ride

public:
    Booking(User *user, Rider *rider, RideVehicle *vehicle, const string &type)
        : user(user), rider(rider), vehicle(vehicle), bookingType(type)
    {
        // generate unique booking ID
        static int idCounter = 1;
        bookingId = "BOOK" + to_string(idCounter++);
        fare = calculateFare();
    }

    double calculateFare()
    {
        if (bookingType == "Bike Booking")
            return 50.0;
        if (bookingType == "Mini Booking")
            return 100.0;
        return 80.0;
    }

    void showBookingDetails()
    {
        cout << "Booking ID: " << bookingId << endl;
        cout << "Type: " << bookingType << endl;
        cout << "Fare: " << fare << endl;
        cout << "User: " << user->getName() << endl;
        cout << "Rider: " << rider->getName() << endl;
    }
};
class BookingFactory
{
public:
    virtual Booking *createBooking(User *user, Rider *rider, RideVehicle *vehicle) = 0;
};
class BikeBookingFactory : public BookingFactory
{
public:
    Booking *createBooking(User *user, Rider *rider, RideVehicle *vehicle) override
    {
        return new Booking(user, rider, vehicle, "Bike Booking");
    }
};
class PaymentStrategy
{
public:
    virtual void processPayment(double amount, User *user, Rider *rider, RideVehicle *vehicle) = 0;
    virtual ~PaymentStrategy() = default;
};
class UPI : public PaymentStrategy
{
public:
    void processPayment(double amount, User *user, Rider *rider, RideVehicle *vehicle) override
    {
        cout << "Paid " << amount << " to " << rider->getName()
             << " by " << user->getName()
             << " for ride " << vehicle->getVehicleName()
             << " using UPI\n";
    }
};
class PaymentProcessor
{
private:
    PaymentStrategy *strategy;
    User *user;
    Rider *rider;
    RideVehicle *vehicle;

public:
    PaymentProcessor(PaymentStrategy *s, User *u, Rider *r, RideVehicle *v)
        : strategy(s), user(u), rider(r), vehicle(v) {}
    void process(double amount)
    {
        strategy->processPayment(amount, user, rider, vehicle);
    }
};
int main()
{
    User *user1 = new User("Mudit", "8920337878");
    Rider *rider1 = new Rider("Yash", "9212388370", nullptr);
    RideVehicle *bike = new Bike("Pulsar", "HR-26AB1234");
    BookingFactory *bikeFactory = new BikeBookingFactory();
    Booking *booking = bikeFactory->createBooking(user1, rider1, bike);
    booking->showBookingDetails();
    UPI upiProcessor;
    PaymentProcessor paymentProcessor(&upiProcessor, user1, rider1, bike);
    paymentProcessor.process(100);
}