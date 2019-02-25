/*
* C++ Design Patterns: Factory Method
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
#include <algorithm>
#include <memory>

/*
* Product
* products implement the same interface so that the classes can refer
* to the interface not the concrete product
*/
class Product {
public:
	virtual std::string getName() const = 0;
	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Product> &product)
	{
		if (product == nullptr) {
			return out << "product empty";
		}
		return out << "product Name : " << product->getName() ;
	}

	virtual ~Product() {}
};

/*
* oncrete Product X
* define product to be created
*/
class ConcreteProduct_X : public Product {
public:
	std::string getName() const override
	{
		return " Product X ";
	}

	~ConcreteProduct_X() {}
};

/*
* Concrete Product Y
* define product to be created
*/
class ConcreteProduct_Y : public Product {
public:
	std::string getName() const override
	{
		return " Product Y ";
	}

	~ConcreteProduct_Y() {}
};

/*
* Creator
* contains the implementation for all of the methods
* to manipulate products except for the factory method
*/
class Creator {
public:
	virtual std::unique_ptr<Product> createProduct(std::string type) = 0;

	virtual ~Creator() {}
};

/*
* Concrete Creator
* implements factory method that is responsible for creating
* one or more concrete products ie. it is class that has
* the knowledge of how to create the products
*/
class ConcreteCreator : public Creator {
public:
	std::unique_ptr<Product> createProduct(std::string type) override
	{
		std::transform(type.begin(), type.end(), type.begin(), tolower);
		if (type == "fr")
		{
			return std::make_unique<ConcreteProduct_X>();
		}
		else if (type == "it")
		{
			return std::make_unique<ConcreteProduct_Y>();
		}
		else
		{
			return nullptr;
		}
	}

	~ConcreteCreator() {}															// destructor
};


int main()
{
	std::unique_ptr<Creator> creatorFr = std::make_unique<ConcreteCreator>();

	std::unique_ptr<Product> productFr = creatorFr->createProduct("FR");
	std::cout << "Product Fr " << productFr << std::endl;

	std::unique_ptr<Product> productIt = creatorFr->createProduct("it");
	std::cout << "Product It " << productIt << std::endl;

	system("pause");
	return 0;
}

