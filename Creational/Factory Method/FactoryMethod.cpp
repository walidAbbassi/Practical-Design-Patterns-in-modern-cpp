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
			return out << "car empty" ;
		}
		return out << "car Name : " << car->getName() << " and Manufacturer by : " << car->getManufacturer();
	}
	// ...
};

/*
* Kangoo Renault Car ==> Concrete Product
* define product to be created
*/
class ConcreteKangoo : public Car {
public:
	std::string getName() const override {
		return " Kangoo ";
	}
	std::string getManufacturer() const override {
		return " Renault ";
	}
	// ...
};

/*
* Fiat Car ==> Concrete Product
* define product to be created
*/
class ConcreteCinquecento : public Car {
public:
	std::string getName() const override {
		return " Cinquecento ";
	}
	std::string getManufacturer() const override {
		return " Fiat ";
	}
	// ...
};

/*
* Creator
* contains the implementation for all of the methods
* to manipulate products except for the factory method
*/
class Creator {
public:
	virtual std::unique_ptr<Car> createProductCar(std::string nationality) = 0;
	// ...
};

/*
* Concrete Creator
* implements factory method that is responsible for creating
* one or more concrete products ie. it is class that has
* the knowledge of how to create the products
*/
class ConcreteCreator : public Creator {
public:
	std::unique_ptr<Car> createProductCar(std::string nationality) override {
		std::transform(nationality.begin(), nationality.end(), nationality.begin(), tolower);
		if (nationality == "fr") {
			return std::make_unique<ConcreteKangoo>();
		}
		else if (nationality == "it") {
			return std::make_unique<ConcreteCinquecento>();
		}
		else {
			return nullptr;
		}
	}
	// ...
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

