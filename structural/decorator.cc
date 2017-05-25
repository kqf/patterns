#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Component
{
public:
    virtual string operation() const = 0;
};


class ConcreteComponent: public Component
{
public:
    virtual string operation() const
    {
        return "I am a concrete component";
    }
};


class Decorator: public Component
{
public:
    // Here Decorator can't exist without component
    Decorator(Component & comp): element(comp) {}

protected:
    Component & element;
};



// Concrete Decorator A
// 
class BlueDecorator: public Decorator
{
public:
    BlueDecorator(Component & comp): Decorator(comp) {}
    virtual string operation() const
    {
        return "\033[1;34m" + element.operation() + "\033[0m";
    }
};

// Concrete Decorator B
// 
class UnderlineDecorator: public Decorator
{
public:
    UnderlineDecorator(Component & comp): Decorator(comp) {}
    virtual string operation() const
    {
        return "\033[4m" + element.operation() + "\033[0m";
    }
};


// Now we are solving a proble of combinatorial classes
// There are a lot of popssibilities to modify a ConcreteComponent.
// 
//

int main(int argc, char const *argv[])
{
    ConcreteComponent comp;
    cout << "Running undecorated component:" << endl;
    cout << comp.operation() << endl << endl;

    Component & blue = * new BlueDecorator(comp);
    cout << "Running decorated component:" << endl;
    cout << blue.operation() << endl << endl;

    Component & underline = * new UnderlineDecorator(comp);
    cout << "Running decorated component:" << endl;
    cout << underline.operation() << endl << endl;

    Component & blueunderline = *new UnderlineDecorator(blue);
    cout << "We can even chain decorators.\nRunning decorated component:" << endl;
    cout << blueunderline.operation() << endl << endl;

    delete &blue;
    delete &underline;
    delete &blueunderline;

    return 0;
}