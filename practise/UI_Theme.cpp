#include <iostream>
using namespace std;

class Button
{
public:
    virtual void element() = 0;
    virtual ~Button() {}
};
class TextBox
{
public:
    virtual void element() = 0;
};

class DarkButton : public Button
{
public:
    void element() override
    {

        cout << "I am Dark Button";
    }
};
class DarkTextBox : public TextBox
{
public:
    void element() override
    {

        cout << "I am Dark TextBox";
    }
};

class LightButton : public Button
{
public:
    void element() override
    {

        cout << "I am White Button";
    }
};
class LightTextBox : public TextBox
{
public:
    void element() override
    {

        cout << "I am White TextBox";
    }
};

class UIFactory
{
public:
    virtual Button *createButton() = 0;
    virtual TextBox *createTextBox() = 0;
};

class DarkFactory : public UIFactory
{
public:
    Button *createButton() override
    {
        return new DarkButton();
    }
    TextBox *createTextBox() override
    {
        return new DarkTextBox();
    }
};
class LightFactory : public UIFactory
{
public:
    Button *createButton() override
    {
        return new LightButton();
    }
    TextBox *createTextBox() override
    {
        return new LightTextBox();
    }
};

int main()
{
    UIFactory *factory = new DarkFactory();
    Button *b = factory->createButton();
    b->element();
    delete b;
    delete factory;
}