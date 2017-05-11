#include <iostream>
#include <string>
#include <list>
#include <algorithm>


using std::list;

// Abstract observer
class Observer
{
public:
	virtual void HandleEvent(int value)  = 0;
};

// Concrecte observer A
class User: public Observer
{
	std::string name;
public:
	User(const char * n): name(n) {}
	virtual void HandleEvent(int t)
	{
		std::cout << "User " << name << ": now I know that temperature is " << t << " C" << std::endl;
	}
};

// Concrecte observer B
class Station: public Observer
{
	int id;
public:
	Station(int i): id(i) {}
	virtual void HandleEvent(int t)
	{
		std::cout << "Weather station # " << id << ": temperature is " << 9. * t / 5 + 32 << " F" << std::endl;
	}
};


// This is the "Subject" class
// 
class Observable
{
protected:
	// Observer collection
	typedef std::list<Observer *> ObserverContainer;
	ObserverContainer observers;

public:
	virtual void Notify() = 0;
	virtual void AddObserver(Observer * o) 
	{
		if (o) observers.push_back(o);
	}

	virtual void DeleteObserver(Observer * o)
	{
		// Here d is some data, o -- object to delete, x -- garbage  in memory
		// Example:
		// Here end is 4 [d, d, o, d] --> [d, d, x, d] --> [d, d ,d, x], here new end is 3
		// More details here:
		// https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom

		ObserverContainer::iterator new_end = std::remove(observers.begin(), observers.end(), o);
		observers.erase(new_end, observers.end());  // remove thrash from container
	}
};

// This is observable class -- represents state of physical thermometer
class Thermometer: public Observable
{
	int temperature;

public:
	Thermometer(): temperature(0) {}
	// This is thermometer specific method;
	void ChageTemperature(int t) { temperature = t; Notify(); }

	virtual void Notify()
	{
		for (ObserverContainer::iterator it = observers.begin(); it != observers.end(); ++it)
			(*it)->HandleEvent(temperature);
	}
};



int main(int argc, char const * argv[])
{
	Thermometer t;
	User * v = new User("Andrew");
	t.AddObserver(new User("Peter"));
	t.AddObserver(v);
	t.AddObserver(new Station(123));
	t.AddObserver(new Station(4140));
	t.ChageTemperature(20);

	t.DeleteObserver(v);
	std::cout << "Now we delteded Vasia from the observers\n" << std::endl;
	t.ChageTemperature(20);
	return 0;
}