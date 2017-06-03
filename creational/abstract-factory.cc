#include <iostream>

using std::cout;
using std::endl;


// Abstract product A
class Button
{
public:
    virtual void click() const = 0;
};

class Window
{
public:
    virtual void show() const = 0;
};


// Abstract product B
class OsxButton: public Button
{
public:
    virtual void click() const 
    {
        cout << "Clicking OSX button: Clack ..." << endl;
    }
};


// Concrete products A, B
//
//

class WinButton: public Button
{
public:
    virtual void click() const 
    {
        cout << "Clicking Win button. Click ..." << endl;
    }
};


class OsxWindow: public Window
{
public:
    virtual void show() const
    {
        cout << "Showing OSX window ..." << endl;
    }
};

class WinWindow: public Window
{
public:
    virtual void show() const
    {
        cout << "Showing Win window ..." << endl;
    }
};


class AbstractFactory
{
public:
    virtual Button * create_button() const = 0;
    virtual Window * create_window() const = 0;
};


// Concrete Factory 1
//
//

class OsxFactory: public AbstractFactory
{
public:
    virtual Button * create_button() const
    {
        return new OsxButton();
    }
    virtual Window * create_window() const
    {
        return new OsxWindow();
    }
};

// Concrete Factory 2
//
//

class WinFactory: public AbstractFactory
{
public:
    virtual Button * create_button() const
    {
        return new WinButton();
    }
    virtual Window * create_window() const
    {
        return new WinWindow();
    }
};


int main(int argc, char const *argv[])
{
    // Client code

    const int size = 3;
    AbstractFactory * factories[size] = {new OsxFactory(), new WinFactory(), new OsxFactory()};

    cout << "Creating windows: " << endl << endl;
    for(int i = 0; i < size; ++i)
    {
        Window * w = factories[i]->create_window();
        w->show();
        delete w;
    }

    cout << endl;
    cout << "Clicking all the buttons: " << endl << endl;
    for(int i = 0; i < size; ++i)
    {
        Button * b = factories[i]->create_button();
        b->click();
        delete b;
    }

    return 0;
}