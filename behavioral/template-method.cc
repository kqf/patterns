#include <iostream>

using std::cout;
using std::endl;


class Query
{
public:
	virtual void execute() 
	{
		const char * data = objects();
		cout << "Establishing connection ..." << endl;
		cout << "Quering: " << data << endl;
		cout << "Done!" << endl;
	}

protected:
	virtual const char * objects() = 0;
};

class FruitQuery: public Query
{
	virtual const char * objects()
	{
		return "Orange, Apple, Banana";
	}
};

class ColorQuery: public Query
{
	virtual const char * objects()
	{
		return "Orange, Blue, Red";
	}
};

void context(Query * l)
{
	l->execute();
}

int main(int argc, char const *argv[])
{

	FruitQuery qfruits;
	context(&qfruits);

	cout << endl << "The same for colors!" << endl << endl;

	ColorQuery qcolors;
	context(&qcolors);

	return 0;
}

