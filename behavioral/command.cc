#include "iostream"
#include "cassert"

using std::cout;
using std::endl;

class Command
{
	double initial;
public:
	Command(double i): initial(i) {}
	virtual double operator()(double v) const = 0; // Execute method
	virtual double GetInitial() const { return initial; }
	virtual ~Command() {}
};

class Sum: public Command // Concrete command 1
{
public:
	Sum(double v): Command(v) {}
	virtual double operator()(double i) const { return i; }
};

class SumOfSquares: public Command // Concrete command 2
{
public:
	SumOfSquares(double v): Command(v) {}
	virtual double operator()(double i) const { return i * i; }
};

class Receiver
{
	int start;
	int stop;
public:
	Receiver(int a, int b): start(a), stop(b) { assert( (start < stop) && "Wrong range specified!"); }
	double Action(Command & cmd) const
	{
		double initial  = cmd.GetInitial();
		for (int i = start; i < stop; ++i)
			initial += cmd((double) i);
		return initial;
	}
};

int main(int argc, char const * argv[])
{
	// Receiver loop(0, 10);
	Sum plainsum(0);
	cout << " Sum is : " << Receiver(0, 10).Action(plainsum) << endl;

	SumOfSquares squares(0);
	cout << " Sum of squares is : " << Receiver(0, 10).Action(squares) << endl;

	return 0;
}