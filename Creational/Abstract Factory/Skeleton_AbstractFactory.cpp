/*
* C++ Design Patterns: Abstract Factory
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
* Product A
* products implement the same interface so that the classes can refer
* to the interface not the concrete product
*/
class Product_A {
public:
	virtual std::string getName() const = 0;
	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Product_A> &product_A)
	{
		return out << "Product A Name : " << product_A->getName();
	}

	virtual ~Product_A() {}
};

/*
* Concrete Product A1
* define objects to be created by concrete factory
*/
class ConcreteProduct_A1 : public Product_A {
public:
	std::string getName() const override
	{
		return " Concrete Product A1 ";
	}

	~ConcreteProduct_A1() {}
};

/*
* Concrete Product A2
* define objects to be created by concrete factory
*/
class ConcreteProduct_A2 : public Product_A {
public:
	std::string getName() const override
	{
		return " Concrete Product A2 ";
	}

	~ConcreteProduct_A2() {}
};

/*
* Product B
* same as Product A, Product B declares interface for concrete products
* where each can produce an entire set of products
*/
class Product_B {
public:
	virtual std::string getName() const = 0;
	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Product_B> &product_B)
	{
		return out << "product B Name : " << product_B->getName();
	}

	virtual ~Product_B() {}
};

/*
* Concrete Product B1
* define objects to be created by concrete factory
*/
class ConcreteProduct_B1 : public Product_B {
public:
	std::string getName() const override
	{
		return " Concrete Product B1 ";
	}

	~ConcreteProduct_B1() {}
};

/*
* Concrete Product B2
* define objects to be created by concrete factory
*/
class ConcreteProduct_B2 : public Product_B {
public:
	std::string getName() const override
	{
		return " Concrete Product B2 ";
	}

	~ConcreteProduct_B2() {}
};

/*
* Abstract Factory
* provides an abstract interface for creating a family of products
*/
class AbstractFactory {
public:
	virtual std::unique_ptr<Product_A> createProduct_A() = 0;
	virtual std::unique_ptr<Product_B> createProduct_B() = 0;

	virtual ~AbstractFactory() {}
};

/*
* Concrete Factory 1
* each concrete factory create a family of products and client uses
* one of these factories so it never has to instantiate a product object
*/
class ConcreteFactory_1 : public AbstractFactory {
public:
	std::unique_ptr<Product_A> createProduct_A() override
	{
		return std::make_unique<ConcreteProduct_A1>();
	}
	std::unique_ptr<Product_B> createProduct_B() override
	{
		return std::make_unique<ConcreteProduct_B1>();
	}

	~ConcreteFactory_1() {}
};

/*
* Concrete Factory 2
* each concrete factory create a family of products and client uses
* one of these factories so it never has to instantiate a product object
*/
class ConcreteFactory_2 : public AbstractFactory {
public:
	std::unique_ptr<Product_A> createProduct_A() override
	{
		return std::make_unique<ConcreteProduct_A2>();
	}
	std::unique_ptr<Product_B> createProduct_B() override
	{
		return std::make_unique<ConcreteProduct_B2>();
	}

	~ConcreteFactory_2() {}
};

/*
* example use of AbstractFactory
*/
void application(AbstractFactory& factory)
{
	std::unique_ptr<Product_A> product_A_ptr = factory.createProduct_A();
	std::unique_ptr<Product_B> product_B_ptr = factory.createProduct_B();
	std::cout << product_A_ptr << std::endl;
	std::cout << product_B_ptr << std::endl;
}

int main()
{
	ConcreteFactory_1  concreteFactory_1;
	ConcreteFactory_2 concreteFactory_2;
	application(concreteFactory_1);
	application(concreteFactory_2);

	std::shared_ptr<ConcreteFactory_1> concreteFactory_1_ptr = std::make_shared<ConcreteFactory_1>();
	std::shared_ptr<ConcreteFactory_2> concreteFactory_2_ptr = std::make_shared<ConcreteFactory_2>();
	std::unique_ptr<Product_A> product_v1 = concreteFactory_1_ptr->createProduct_A();
	std::cout << "Product 1: " << product_v1->getName() << std::endl;
	std::unique_ptr<Product_A> product_v2 = concreteFactory_2_ptr->createProduct_A();
	std::cout << "Product 2 : " << product_v2->getName() << std::endl;

	system("pause");
	return 0;
}
