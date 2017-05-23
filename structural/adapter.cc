#include <iostream>

using std::cout;
using std::endl;


// A new interface that we should adapt to the old one
// 
//

class Adaptee
{
public:
    void method_f() const
    {
        cout << "I am using a custom library..." << endl;
    }

};


// Old interface that we are going to replace
// 
// 

class OldInterface
{
public:
    static OldInterface * create();
    virtual void method_g() const
    {
        cout << "I am using a default library..." << endl;
    }
};


class Adapter: public OldInterface
{
public:
    Adapter(): OldInterface(), customlib() {}
    virtual void method_g() const
    {
        customlib.method_f();
    }

private:
    Adaptee customlib;
};


OldInterface * OldInterface::create()
{
    // Was when we used old interface
    // return new OldInterface();

    // Now, when we start using new library
    return new Adapter();
}


int main(int argc, char const *argv[])
{
    OldInterface * lib = OldInterface::create();
    lib->method_g();
    delete lib;

    return 0;
}