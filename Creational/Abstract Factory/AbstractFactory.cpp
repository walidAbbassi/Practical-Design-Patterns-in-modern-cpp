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
* Car  ==>  Product A
* products implement the same interface so that the classes can refer
* to the interface not the concrete product
*/
class Car {
public:
	virtual std::string getName() const = 0;
	virtual std::string getManufacturer() const = 0;
	friend std::ostream &operator<<(std::ostream &o, const std::unique_ptr<Car> &car)
	{
		return o << "car Name : " << car->getName() << " and Manufacturer by : " << car->getManufacturer();
	}
	// ...
};

/*
* Renault Car ==> Concrete ProductA1 
* define objects to be created by concrete factory
*/
class Kangoo : public Car {
public:
	std::string getName() const {
		return " Kangoo ";
	}
	std::string getManufacturer() const {
		return " Renault ";
	}
	// ...
};

/*
* Fiat Car ==> Concrete ProductA2
* define objects to be created by concrete factory
*/
class Cinquecento : public Car {
public:
	std::string getName() const {
		return " Cinquecento ";
	}
	std::string getManufacturer() const {
		return " Fiat ";
	}
	// ...
};

/*
* Truck  ==> Product B
* same as Product A, Product B declares interface for concrete products
* where each can produce an entire set of products
*/
class Truck {
public:
	virtual std::string getName() const = 0;
	virtual std::string getManufacturer() const = 0;
	friend std::ostream &operator<<(std::ostream &o, const std::unique_ptr<Truck> &truck)
	{
		return o << "truck Name : " << truck->getName() << " and Manufacturer by : " << truck->getManufacturer();
	}
	// ...
};

/*
* Fiat Truck ==> Concrete ProductB1
* define objects to be created by concrete factory
*/
class Maxity : public Truck {
public:
	std::string getName() const {
		return " Maxity ";
	}
	std::string getManufacturer() const {
		return " Renault ";
	}
	// ...
};

/*
* Fiat Truck ==> Concrete ProductB2
* define objects to be created by concrete factory
*/
class Ducato : public Truck {
public:
	std::string getName() const {
		return " Ducato ";
	}
	std::string getManufacturer() const {
		return " Fiat ";
	}
	// ...
};

/*
* Abstract Factory
* provides an abstract interface for creating a family of products
*/
class AbstractFactory {
public:
	virtual std::unique_ptr<Car> createCar() = 0;		// virtual ProductA *createProductA() = 0;
	virtual std::unique_ptr<Truck> createTruck() = 0;	// virtual ProductB *createProductB() = 0;
};

/*
* Concrete Factory French
* each concrete factory create a family of products and client uses
* one of these factories so it never has to instantiate a product object
*/
class ConcreteFactoryFrench : public AbstractFactory {
public:
	std::unique_ptr<Car> createCar() {
		return std::make_unique<Kangoo>();
	}
	std::unique_ptr<Truck> createTruck() {
		return std::make_unique<Maxity>();
	}
	// ...
};

/*
* Concrete Factory Italian
* each concrete factory create a family of products and client uses
* one of these factories so it never has to instantiate a product object
*/
class ConcreteFactoryItalian : public AbstractFactory {
public:
	std::unique_ptr<Car> createCar() {
		return std::make_unique<Cinquecento>();
	}
	std::unique_ptr<Truck> createTruck() {
		return std::make_unique<Ducato>();
	}
	// ...
};

/*
* example use of AbstractFactory
*/
void application(AbstractFactory& factory) {
	std::unique_ptr<Car> car_ptr = factory.createCar();
	std::unique_ptr<Truck> truck_ptr = factory.createTruck();
	std::cout << car_ptr << std::endl;
	std::cout << truck_ptr << std::endl;
}

int main()
{
	ConcreteFactoryFrench  factoryFrench;
	ConcreteFactoryItalian factoryItalian;
	application(factoryFrench);
	application(factoryItalian);

	ConcreteFactoryFrench *factoryFrench_ptr = new ConcreteFactoryFrench();
	ConcreteFactoryItalian *factoryItalian_ptr = new ConcreteFactoryItalian();
	std::unique_ptr<Car> car1 = factoryFrench_ptr->createCar();
	std::cout << "Product car1: " << car1->getName() << std::endl;
	std::unique_ptr<Car> car2 = factoryItalian_ptr->createCar();
	std::cout << "Product car2 : " << car2->getName() << std::endl;

	system("pause");
	return 0;
}
