#include <iostream>

using std::cout;
using std::endl;

// Mayers singleton
//
//

class Singleton
{
public:
    static const Singleton& Instance()
    {

        cout << "Creating only one instance " << endl;
        // Static variable does the trick
        static Singleton theSingleInstance;
        return theSingleInstance;
    }
private:
    Singleton() {}
    // These both methods shouldn't be defined
    Singleton(const Singleton& root);
    Singleton& operator=(const Singleton&);
};


int main(int argc, char const *argv[])
{
    const Singleton & s = Singleton::Instance();
    return 0;
}