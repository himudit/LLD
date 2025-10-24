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

int main(){
    Rectangle rect(4,5);
    cout << rect.area();
}