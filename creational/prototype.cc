#include <iostream>

using std::cout;
using std::endl;


class Prototype
{
public:
	virtual ~Prototype() {}
	virtual void show() const = 0;
	virtual Prototype * clone() const = 0;
};


class Triangle: public Prototype
{
public:
	virtual void show() const 
	{
		cout << "Drawing a triangle with fairly complex cnfigurations" << endl;
	}

	virtual Prototype * clone() const
	{
		// complex logic can be handled here
		// 
		// 
		Prototype * p = new Triangle(*this);
		return p;
	}

};

class Square: public Prototype
{
public:
	virtual void show() const 
	{
		cout << "Drawing a square with fairly complex cnfigurations" << endl;
	}

	virtual Prototype * clone() const
	{
		// complex logic can be handled here
		// 
		// 
		Prototype * p = new Square(*this);
		return p;
	}

};


class Client
{
public:
	Client(): prot_triangle(new Triangle()), prot_square(new Square()) {}
	~Client()
	{
		delete prot_triangle;
		delete prot_square;
	}

	Prototype * operator()(int a) const
	{
		if(a > 10)
			return prot_square->clone();

		return prot_triangle->clone();
	}
private:
	Prototype * prot_triangle;
	Prototype * prot_square;
};


int main(int argc, char const *argv[])
{
	Client myclient;

	Prototype * obj1 = myclient(1);
	obj1->show();

	Prototype * obj2 = myclient(137);
	obj2->show();

	return 0;
}