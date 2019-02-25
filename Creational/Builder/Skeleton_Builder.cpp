/*
* C++ Design Patterns: Builder
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <ostream>
#include <string>
#include <memory>

/*
* Product
* the final object that will be created using Builder
*/
class Product {
public:
	void makePart1(const std::string &part)
	{
		part1 = part;
	}
	void makePart2(const std::string &part)
	{
		part2 = part;
	}
	void makePart3(const std::string &part)
	{
		part3 = part;
	}

	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Product> &product)
	{
		return out << " part 1 : " << product->part1 << " , part 2 : " << product->part2 << " and part3 : " << product->part3;
	}

	~Product() {}

private:
	std::string part1;
	std::string part2;
	std::string part3;
	// ...
};

/*
* Builder
* abstract interface for creating products
*/
class Builder {
public:

	virtual void buildPart1(const std::unique_ptr<Product> &product) = 0;
	virtual void buildPart2(const std::unique_ptr<Product> &product) = 0;
	virtual void buildPart3(const std::unique_ptr<Product> &product) = 0;

	virtual ~Builder() {}
};

/*
* Concrete Builder X
* create real products and stores them in the composite structure
*/
class ConcreteBuilder_X : public Builder {
public:
	void buildPart1(const std::unique_ptr<Product> &product) override
	{
		product->makePart1("build_X_Part1");
	}
	void buildPart2(const std::unique_ptr<Product> &product) override
	{
		product->makePart2("build_X_Part2");
	}
	void buildPart3(const std::unique_ptr<Product> &product) override
	{
		product->makePart3("build_X_Part3");
	}

	~ConcreteBuilder_X() {}
};

/*
* Concrete Builder Y
* create real products and stores them in the composite structure
*/
class ConcreteBuilder_Y : public Builder {
public:
	void buildPart1(const std::unique_ptr<Product> &product) override
	{
		product->makePart1("build_Y_Part1");
	}
	void buildPart2(const std::unique_ptr<Product> &product) override
	{
		product->makePart2("build_Y_Part2");
	}
	void buildPart3(const std::unique_ptr<Product> &product) override
	{
		product->makePart3("build_Y_Part3");
	}

	~ConcreteBuilder_Y() {}
};

/*
* Director
* responsible for managing the correct sequence of object creation
*/
class Director {
public:
	Director(const std::shared_ptr<Builder> &builder) : builder_ptr(builder) {}

	void set(const std::shared_ptr<Builder> &builder)
	{
		if (!builder_ptr.expired())
		{
			builder_ptr.reset();	//builder_ptr = nullptr;
		}
		builder_ptr = builder;
	}


	std::unique_ptr<Product> construct()
	{
		std::unique_ptr<Product> product = std::make_unique<Product>();
		builder_ptr.lock()->buildPart1(product);
		builder_ptr.lock()->buildPart2(product);
		builder_ptr.lock()->buildPart3(product);
		return product;
		// ...
	}

	~Director() {}

private:
	std::weak_ptr<Builder> builder_ptr;
};

int main()
{
	std::shared_ptr<Builder> concreteBuilder_X= std::make_shared<ConcreteBuilder_X>();
	Director director(concreteBuilder_X);
	std::unique_ptr<Product> product_X = director.construct();
	std::cout << "product X " << product_X << std::endl;

	std::shared_ptr<Builder> concreteBuilder_Y = std::make_shared<ConcreteBuilder_Y>();
	director.set(concreteBuilder_Y);
	std::unique_ptr<Product> product_Y = director.construct();
	std::cout << "product X " << product_Y << std::endl;

	system("pause");
	return 0;
}
