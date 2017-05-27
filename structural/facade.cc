#include <iostream>

using std::cout;
using std::endl;


class Package1
{
public:
	void f() const 
	{
		cout << "Invoking the first package" << endl;
	}
};

class Package2
{
public:
	void g() const 
	{
		cout << "Invoking the second package" << endl;
	}
};

class Facade
{
public:
	void doSomething() const
	{
		// This method contains complex logic
		// of interaction of packages 1,2

		cout << "Initializing" << endl;
		Package1 a;
		Package2 b;

		// Some code
		a.f();
		b.g();

		cout << "Running some code" << endl;
		// Some more code
		Package2 c;
		c.g();
	}
};


int main(int argc, char const *argv[])
{
	Facade f;
	f.doSomething();
	return 0;
}