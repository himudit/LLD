#include <bits/stdc++.h>
using namespace std;

enum MainItem
{
    BURGER,
    PIZZA,
    SANDWICH
};

enum Drink
{
    COKE,
    JUICE,
    COFFEE
};

enum Extras
{
    CHEESE,
    EXTRA_SAUCE,
    DOUBLE_PATTY
};

class Meal
{
private:
    MainItem item;
    bool hasDrink;
    Drink drink;
    vector<Extras> extras;

    // Private constructor
    Meal(MainItem item, bool hasDrink, Drink drink, vector<Extras> extras)
        : item(item), hasDrink(hasDrink), drink(drink), extras(extras) {}

public:
    void showDetails()
    {
        cout << "Main Item: " << item << endl;

        if (hasDrink)
            cout << "Drink: " << drink << endl;
        else
            cout << "Drink: None" << endl;

        cout << "Extras: ";
        for (auto e : extras)
            cout << e << " ";
        cout << endl;
    }

    friend class MealBuilder;
};

class MealBuilder
{
private:
    MainItem item;
    bool hasDrink = false;
    Drink drink;
    vector<Extras> extras;

public:
    // Mandatory field
    MealBuilder(MainItem item) : item(item) {}

    MealBuilder &setDrink(Drink d)
    {
        drink = d;
        hasDrink = true;
        return *this;
    }

    MealBuilder &addExtra(Extras e)
    {
        extras.push_back(e);
        return *this;
    }

    Meal build()
    {
        return Meal(item, hasDrink, drink, extras);
    }
};

int main()
{
    Meal m1 = MealBuilder(BURGER)
                  .setDrink(COKE)
                  .addExtra(CHEESE)
                  .build();

    m1.showDetails();
}