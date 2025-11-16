#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class PaymentStrategy
{
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentStrategy() = default;
};
class CreditCard : public PaymentStrategy
{
public:
    void processPayment(double amount)
    {
        cout << "Payment of " << amount << "done by Credit Card" << endl;
    }
};
class UPI : public PaymentStrategy
{
public:
    void processPayment(double amount)
    {
        cout << "Payment of " << amount << "done by UPI" << endl;
    }
};
class PaymentProcessor
{
private:
    PaymentStrategy *ps;

public:
    PaymentProcessor(PaymentStrategy *ps)
    {
        this->ps = ps;
    }
    void process(double amount)
    {
        ps->processPayment(amount);
    }
};
int main()
{
    PaymentStrategy *creditCard = new CreditCard();
    PaymentStrategy *upi = new UPI();
    PaymentProcessor *ps1 = new PaymentProcessor(creditCard);
    PaymentProcessor *ps2 = new PaymentProcessor(upi);
    ps2->process(10000);
    ps1->process(300);
}