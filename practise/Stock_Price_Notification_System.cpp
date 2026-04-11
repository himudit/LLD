#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Observer
{
public:
    virtual void update(const string &stockName, int price) = 0;
};
class User : public Observer
{
private:
    string name;
    int threshold;

public:
    User(string name, int threshold) : name(name), threshold(threshold) {}
    void update(const string &stockName, int price)
    {
        if (price > threshold)
        {
            cout << name << " notified: " << stockName << " -> " << price << endl;
        }
    }
};
class Subject
{
public:
    virtual void subscribe(Observer *obs) = 0;
    virtual void unsubscribe(Observer *obs) = 0;
    virtual void setPrice(int newPrice) = 0;
};
class Stock : public Subject
{
private:
    string name;
    int price;
    set<Observer *> users;

public:
    Stock(string name, int price) : name(name), price(price) {}
    void subscribe(Observer *obs)
    {
        users.insert(obs);
    }
    void unsubscribe(Observer *obs)
    {
        users.erase(obs);
    }
    void setPrice(int newPrice)
    {
        price = newPrice;
        notify();
    }
    void notify()
    {
        for (auto *user : users)
        {
            user->update(name, price);
        }
    }
};
int main()
{
    Observer *t1 = new User("Mudit", 90);
    Observer *t2 = new User("Aman", 80);

    Subject *AAPL = new Stock("AAPL", 70);

    AAPL->subscribe(t1);
    AAPL->subscribe(t2);

    AAPL->setPrice(100); // both get notified

    AAPL->unsubscribe(t1);

    AAPL->setPrice(85); // only Aman may get notified

    delete t1;
    delete t2;
    delete AAPL;
}