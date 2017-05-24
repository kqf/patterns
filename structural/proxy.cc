#include <iostream>

using std::cout;
using std::endl;

class Subject
{
public:
    virtual void action() const = 0;
};


class RealSubject: public Subject
{
public:
    virtual void action() const 
    {
        cout << "Running a real object, please wait ..." << endl;
    }
};


class Proxy: public Subject
{
public:
    Proxy(RealSubject & s): subj(s) {}
    virtual void action() const
    {
        cout << "Proxy start:" << endl;
        cout << "Some processing is going on" << endl;
        cout << "\033[95m";
        subj.action();
        cout << "\033[0m";
        cout << "Proxy has stopped ..." << endl;
    }

private:
    RealSubject & subj;
};


int main(int argc, char const *argv[])
{
    cout << "Direct access:" << endl << endl;
    RealSubject & direct = * new RealSubject();
    direct.action();
    cout << endl;


    cout << "Proxy access:" << endl  << endl;
    Subject & subj = * new Proxy(direct);
    subj.action();
    cout << endl;
    return 0;
}