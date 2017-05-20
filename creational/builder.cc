#include <iostream>

using std::cout;
using std::endl;

class Product
{
public:
	class builder;

	Product(): name("not specified"), weight(0), height(0), length(0), id(0) {}
	void show() const
	{
		cout << "The product " << name << ", id: " << id << endl;
		cout << "length: " << length  << ", height " << height << ", weight: " << weight;
		cout << endl;
	}

private:
	// A lot of different configurations
	const char * name;
	float weight;
	float height;
	float length;
	int id;
};

class Product::builder
{
public:
	builder(): prod() {}

	Product get_product() const { return prod; }


	builder & set_name(const char * name)
	{
		prod.name = name;
		return *this;
	}

	builder & set_id(int id)
	{
		prod.id = id;
		return *this;
	}

	builder & set_weight(float weight)
	{
		prod.weight = weight;
		return *this;
	}

	builder & set_length(float length)
	{
		prod.length = length;
		return *this;
	}

	builder & set_height(float height)
	{
		prod.height = height;
		return *this;
	}
private:
	Product prod;

};

// Director 
// fairly complex logic of creation goes here
//
class Director
{
public:
	Product create(int i = 137) const
	{
		Product::builder b;
		if (i == 137)
		{
			b.set_name("TV set").set_id(i).set_height(123).set_length(234).set_weight(5);
			return b.get_product();
		}
		b.set_name("glass block");
		b.set_id(i);
		b.set_height(13);
		b.set_length(24);
		b.set_weight(1);
		return b.get_product();
	}

};

int main(int argc, char const * argv[])
{
	Director d;
	Product p1  = d.create();
	p1.show();

	Product p2  = d.create(35);
	p2.show();
	

	return 0;
}