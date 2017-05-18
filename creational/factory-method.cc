#include <iostream>

using std::cout;
using std::endl;


class Shape
{
public:

	virtual void draw() const = 0;
	static Shape * create(int i);
};


class Triangle: public Shape
{
public:
	virtual void draw() const
	{
		cout << "I am a triangle" << endl;
	}

};

class Circle: public Shape
{
public:
	virtual void draw() const
	{
		cout << "I am a circle" << endl;
	}

};

class Point: public Shape
{
public:
	virtual void draw() const
	{
		cout << "I am a point" << endl;
	}

};

class Segment: public Shape
{
public:
	virtual void draw() const
	{
		cout << "I am a segment" << endl;
	}

};

// Adding a new shape results in a modification of this method only
Shape * Shape::create(int i)
{
	if (i == 0)
		return new Circle();

	if (i == 1)
		return new Point();

	if (i == 2)
		return new Segment();

	if (i == 3)
		return new Triangle();

	return 0;

}

int main(int argc, char const * argv[])
{
	int size = 5;
	Shape * shapes[size];

	// Uniform interface
	//

	for(int i = 0; i < size; ++i)
		shapes[i] = Shape::create(i);

	for(int i = 0; i < size; ++i)
	{
		if(shapes[i])
			shapes[i]->draw();
	}

	return 0;
}