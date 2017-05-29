#include <iostream>

using std::cout;
using std::endl;

// Abstract Implementator
class Color
{
public:
    virtual const char * data() const = 0;
};

// Concrete implementators
// 

class Blue: public Color
{
public:
    virtual const char * data() const
    {
        return "blue";
    }
};

class Red: public Color
{
public:
    virtual const char * data() const
    {
        return "blue";
    }
};


// Abstraction
//
class Shape
{
public:
    Shape(Color * c): color(c) {}
    void print() const
    {
        cout << "This is a " << color->data() << " " << name() << "." << endl;
    }

    virtual ~Shape()
    {
        delete color;
    }

protected:
    virtual const char * name() const = 0;

private: 
    Color * color;
};


//  Concrete Abstraction
//
class Circle: public Shape
{
public:
    Circle(Color * c): Shape(c) {}
protected:
    virtual const char * name() const
    {
        return "circle";
    }

};

//  Concrete Abstraction
//
class Triangle: public Shape
{
public:
    Triangle(Color * c): Shape(c) {}
protected:
    virtual const char * name() const
    {
        return "triangle";
    }

};


int main(int argc, char const *argv[])
{
    Circle a(new Blue());
    a.print();

    Circle b(new Red());
    b.print();

    Triangle c(new Red());
    c.print();

    return 0;
}