#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Observer
{
public:
    virtual void update(const string &msg) = 0;
};

class Subject
{
public:
    virtual void attach(Observer *obs) = 0;
    virtual void detach(Observer *obs) = 0;
    virtual void notify(string msg) = 0;
};

class Channel : public Subject
{
private:
    vector<Observer *> subscriber;

public:
    void attach(Observer *Obs) override
    {
        subscriber.push_back(Obs);
    }
    void detach(Observer *Obs) override
    {
        // write logic for detaching the subscriber
    }
    void notify(string msg) override
    {
        for (auto *sub : subscriber)
        {
            sub->update(msg);
        }
    }
};

class Subscriber : public Observer
{
private:
    string name;

public:
    Subscriber(string n) : name(n) {}
    void update(const string &msg) override
    {
        cout << name << " received notification: " << msg << endl;
    }
};

int main()
{
    Observer *s1 = new Subscriber("MUDIT");
    Observer *s2 = new Subscriber("ALOK");
    Observer *s3 = new Subscriber("NAVEEN");

    Subject *bbkiVines = new Channel();
    bbkiVines->attach(s1);
    bbkiVines->attach(s2);
    bbkiVines->attach(s3);
    bbkiVines->notify("New Video aa gayi guys");
}