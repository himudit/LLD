#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Laptop
{
protected:
    string CPU = "100";
    string GPU = "120";
    int RAM = 130;
    int storage = 140;

public:
    void specs()
    {
        cout << CPU << endl;
        cout << GPU << endl;
        cout << RAM << endl;
        cout << storage << endl;
    }
    virtual void use() = 0;
};

class GamingLaptop : public Laptop
{
public:
    void use() override
    {
        cout << "You have Gaming Laptop" << endl;
    }
};

class UltraBook : public Laptop
{
public:
    void use() override
    {
        cout << "You have UltraBook" << endl;
    }
    friend class UltraBookBuilder;
};

class LaptopFactory
{
public:
    virtual Laptop *createLaptop() = 0;
};

class GamingLaptopFactory : public LaptopFactory
{
public:
    Laptop *createLaptop()
    {
        return new GamingLaptop();
    }
};

class UltraBookFactory : public LaptopFactory
{
public:
    Laptop *createLaptop()
    {
        return new UltraBook();
    }
};

class UltraBookBuilder
{
private:
    UltraBook *laptop;

public:
    UltraBookBuilder()
    {
        this->laptop = new UltraBook();
    }
    UltraBookBuilder &setCPU(string cpu)
    {
        laptop->CPU = cpu;
        return *this;
    }
    UltraBookBuilder &setGPU(string gpu)
    {
        laptop->GPU = gpu;
        return *this;
    }
    UltraBookBuilder &setRAM(int RAM)
    {
        laptop->RAM = RAM;
        return *this;
    }
    UltraBookBuilder &setStorage(int strorage)
    {
        laptop->storage = strorage;
        return *this;
    }
    UltraBook *build()
    {
        return laptop;
    }
};

int main()
{
    LaptopFactory *factory;
    factory = new GamingLaptopFactory();

    Laptop *gL = factory->createLaptop();
    gL->use();
    gL->specs();

    factory = new UltraBookFactory();
    Laptop *uB = factory->createLaptop();
    uB->use();
    uB->specs();
}