#include <bits/stdc++.h>
using namespace std;

class Coffee
{
public:
    virtual string getDesciption() = 0;
    virtual double getCost() = 0;
};
class Capuuccino : public Coffee
{
public:
    string getDesciption() override
    {
        return "Capuucciono";
    }
    double getCost() override
    {
        return 3.04;
    }
};
class CoffeeDecorator : public Coffee
{
public:
    Coffee *coffee;
    CoffeeDecorator(Coffee *coffee)
    {
        this->coffee = coffee;
    }
    string getDesciption() override
    {
        return coffee->getDesciption();
    }
    double getCost() override
    {
        return coffee->getCost();
    }
};
class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(Coffee *coffeee) : CoffeeDecorator(coffeee) {}
    string getDesciption() override
    {
        return coffee->getDesciption() + " Milk";
    }
    double getCost() override
    {
        return coffee->getCost() + 0.50;
    }
};
int main()
{
    Coffee *coffee = new Capuuccino();
    coffee = new MilkDecorator(coffee);

    cout << coffee->getDesciption() << " ";
    cout << coffee->getCost() << endl;
}