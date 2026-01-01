#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class CharacterPrototype
{
public:
    virtual void show() = 0;
    virtual CharacterPrototype *clone() = 0;
    virtual ~CharacterPrototype() {}
};

class GameCharacter : public CharacterPrototype
{
private:
    string name;
    int health;
    string weapon;

public:
    void setName(string n)
    {
        this->name = n;
    }
    void setHealth(int h)
    {
        this->health = h;
    }
    void setWeapon(string w)
    {
        this->weapon = w;
    }
    void show()
    {
        cout << this->name << " " << this->health << " " << this->weapon << endl;
    }
    GameCharacter *clone()
    {
        return new GameCharacter(*this);
    }
};

int main(){
    GameCharacter *prototype = new GameCharacter();
    prototype->setName("Default Name");
    prototype->setHealth(100);
    prototype->setWeapon("Default Weapon");

    GameCharacter *guts = prototype->clone();
    guts->setName("Guts");
    guts->setWeapon("Blade");

    guts->show();
}