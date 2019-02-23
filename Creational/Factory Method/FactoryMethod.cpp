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
* Car  ==>  Product
* products implement the same interface so that the classes can refer
* to the interface not the concrete product
*/
class Car {
public:
	virtual std::string getName() const = 0;
	virtual std::string getManufacturer() const = 0;
	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Car> &car)
	{
		if (car == nullptr) {
			return out << "car empty";
		}
		return out << "car Name : " << car->getName() << " and Manufacturer by : " << car->getManufacturer();
	}

	// ... constructor (you can make what you need)
	Car() = default;					// default constructor
	Car(const Car& car) = delete;				// copy constructor
	Car(Car&& car) = delete;				// move constructor
	virtual ~Car() {}					// destructor
};

/*
* Kangoo Renault Car ==> Concrete Product
* define product to be created
*/
class ConcreteKangoo : public Car {
public:
	std::string getName() const override 
	{
		return " Kangoo ";
	}
	std::string getManufacturer() const override 
	{
		return " Renault ";
	}

	// ... constructor (you can make what you need)
	ConcreteKangoo() = default;							// default constructor
	ConcreteKangoo(const ConcreteKangoo& concreteKangoo) = delete;			// copy constructor
	ConcreteKangoo operator=(const ConcreteKangoo& concreteKangoo) = delete;	// copy assignment operator
	ConcreteKangoo(ConcreteKangoo&& concreteKangoo) = delete;			// move constructor
	ConcreteKangoo operator=(ConcreteKangoo&& concreteKangoo) = delete;		// move assignment operator
	~ConcreteKangoo() {}								// destructor
};

/*
* Fiat Car ==> Concrete Product
* define product to be created
*/
class ConcreteCinquecento : public Car {
public:
	std::string getName() const override 
	{
		return " Cinquecento ";
	}
	std::string getManufacturer() const override 
	{
		return " Fiat ";
	}

	// ... constructor (you can make what you need)
	ConcreteCinquecento() = default;								// default constructor
	ConcreteCinquecento(const ConcreteCinquecento& concreteCinquecento) = delete;			// copy constructor
	ConcreteCinquecento operator=(const ConcreteCinquecento& concreteCinquecento) = delete;		// copy assignment operator
	ConcreteCinquecento(ConcreteCinquecento&& concreteCinquecento) = delete;			// move constructor
	ConcreteCinquecento operator=(ConcreteCinquecento&& concreteCinquecento) = delete;		// move assignment operator
	~ConcreteCinquecento() {}									// destructor
};

/*
* Creator
* contains the implementation for all of the methods
* to manipulate products except for the factory method
*/
class Creator {
public:
	virtual std::unique_ptr<Car> createProductCar(std::string nationality) = 0;

	// ... constructor (you can make what you need)
	Creator() = default;								// default constructor
	Creator(const Creator& creator) = delete;					// copy constructor
	Creator(Creator&& creator) = delete;						// move constructor
	virtual ~Creator() {}								// destructor
};

/*
* Concrete Creator
* implements factory method that is responsible for creating
* one or more concrete products ie. it is class that has
* the knowledge of how to create the products
*/
class ConcreteCreator : public Creator {
public:
	std::unique_ptr<Car> createProductCar(std::string nationality) override 
	{
		std::transform(nationality.begin(), nationality.end(), nationality.begin(), tolower);
		if (nationality == "fr") 
		{
			return std::make_unique<ConcreteKangoo>();
		}
		else if (nationality == "it") 
		{
			return std::make_unique<ConcreteCinquecento>();
		}
		else 
		{
			return nullptr;
		}
	}

	// ... constructor (you can make what you need)
	ConcreteCreator() = default;													// default constructor
	ConcreteCreator(const ConcreteCreator& concreteCreator) = delete;		// copy constructor
	ConcreteCreator operator=(const ConcreteCreator& concreteCreator) = delete;	// copy assignment operator
	ConcreteCreator(ConcreteCreator&& concreteCreator) = delete;			// move constructor
	ConcreteCreator operator=(ConcreteCreator&& concreteCreator) = delete;		// move assignment operator
	~ConcreteCreator(){}															// destructor
};


int main()
{
	std::unique_ptr<Creator> creatorFr = std::make_unique<ConcreteCreator>();

	std::unique_ptr<Car> carFr = creatorFr->createProductCar("FR");
	std::cout << "Product car Fr " << carFr << std::endl;

	std::unique_ptr<Car> carIt = creatorFr->createProductCar("it");
	std::cout << "Product car It " << carIt << std::endl;

	system("pause");
	return 0;
}

