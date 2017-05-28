#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;


// Warning: This code contains lambdas, use --std=c++11 flag.
//


// Concrete flyweight
// There are can be multiple concrete flyweights
// for that purpuse use inheritance
class Integer
{
public:
	Integer(int i): value(i) 
	{
		cout << "Debug info: creating Integer instance with value: " << value << endl;
	}

	void operation() const
	{
		cout << value << endl;
	}

	// Enable find
	bool operator==(int rhs) const
	{
		return value == rhs;
	}

protected:
	int value;

};


// Flyweight factory
class IntegerFactory
{
	typedef std::vector<Integer> PoolType;

public:
	Integer & integer(int value)
	{
		// NB: Here objects are mutable
		PoolType::iterator it = find_if(pool.begin(), pool.end(), 
			[value](Integer & element) 
			{ 
				return element == value;
			}
		);

		if(it == pool.end())
		{
			pool.push_back(Integer(value));
			return pool.back();

		}

		return *it;
	}

private:
	// We will rarely remove something from the pool
	//

	PoolType pool;
};


int main(int argc, char const *argv[])
{
	// Client code
	IntegerFactory integers;

	// Initializing poll with numbers starting from 1 to 10
	cout << "Initializing the pool" << endl;
	for(int i = 0; i < 10; ++i)
		integers.integer(i);

	cout << "The pool have been initialized." << endl << endl;

	cout << "Trying to create existing value: " << endl;
	Integer i = integers.integer(5);

	i.operation();
	return 0;
}