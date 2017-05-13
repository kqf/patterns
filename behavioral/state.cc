#include <iostream>
using namespace std;

class Device;

// Abstract State
class State
{
public:
    // Handle Methods
    virtual void on(Device * d) = 0;
    virtual void off(Device * d) = 0;
};

class Device
{
public:
    Device();

    // External "request" methods
    // 

    void start()
    {
        state->on(this);
    }

    void stop()
    {
        state->off(this);
    }

    void setState(State * s)
    {
        state = s;
    }

private:
    State * state;
};


class StateOn: public State
{
public:
    virtual void on(Device * d)
    {
        cout << "Device is ON. Nothing to do ..." << endl;
    }

    void off(Device * d);
};

class StateOff: public State
{
public:
    void on(Device * d)
    {
        cout << "Turning on the Device." << endl;
        d->setState(new StateOn());
        delete this;
    }

    virtual void off(Device * d)
    {
        cout << "Device is OFF. Nothing to do ..." << endl;
    }

};

void StateOn::off(Device * d)
{
    cout << "Turning off the Device."  << endl;
    d->setState(new StateOff());
    delete this;
}

Device::Device(): state(new StateOff())
{
}

int main()
{
    Device example;
    example.stop();
    example.start();
    example.start();
    example.stop();
}
