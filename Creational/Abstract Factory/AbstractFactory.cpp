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
	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Car> &car)
	{
		return out << "car Name : " << car->getName() << " and Manufacturer by : " << car->getManufacturer();
	}

	// ... constructor (you can make what you need)
	Car() = default;					// default constructor
	Car(const Car& car) = delete;				// copy constructor
	Car(Car&& car) = delete;				// move constructor
	virtual ~Car() {}					// destructor
};

/*
* Renault Car ==> Concrete ProductA1
* define objects to be created by concrete factory
*/
class Kangoo : public Car {
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
	Kangoo() = default;					// default constructor
	Kangoo(const Kangoo& kangoo) = delete;			// copy constructor
	Kangoo operator=(const Kangoo& kangoo) = delete;	// copy assignment operator
	Kangoo(Kangoo&& kangoo) = delete;			// move constructor
	Kangoo operator=(Kangoo&& kangoo) = delete;		// move assignment operator
	~Kangoo() {}						// destructor
};

/*
* Fiat Car ==> Concrete ProductA2
* define objects to be created by concrete factory
*/
class Cinquecento : public Car {
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
	Cinquecento() = default;						// default constructor
	Cinquecento(const Cinquecento& cinquecento) = delete;			// copy constructor
	Cinquecento operator=(const Cinquecento& cinquecento) = delete;		// copy assignment operator
	Cinquecento(Cinquecento&& cinquecento) = delete;			// move constructor
	Cinquecento operator=(Cinquecento&& cinquecento) = delete;		// move assignment operator
	~Cinquecento() {}							// destructor
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
	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Truck> &truck)
	{
		return out << "truck Name : " << truck->getName() << " and Manufacturer by : " << truck->getManufacturer();
	}

	// ... constructor (you can make what you need)
	Truck() = default;					// default constructor
	Truck(const Truck& truck) = delete;			// copy constructor
	Truck(Truck&& truck) = delete;				// move constructor
	virtual ~Truck() {}					// destructor
};

/*
* Fiat Truck ==> Concrete ProductB1
* define objects to be created by concrete factory
*/
class Maxity : public Truck {
public:
	std::string getName() const override 
	{
		return " Maxity ";
	}
	std::string getManufacturer() const override 
	{
		return " Renault ";
	}

	// ... constructor (you can make what you need)
	Maxity() = default;						// default constructor
	Maxity(const Maxity& maxity) = delete;				// copy constructor
	Maxity operator=(const Maxity& maxity) = delete;		// copy assignment operator
	Maxity(Maxity&& maxity) = delete;				// move constructor
	Maxity operator=(Maxity&& maxity) = delete;			// move assignment operator
	~Maxity() {}							// destructor
};

/*
* Fiat Truck ==> Concrete ProductB2
* define objects to be created by concrete factory
*/
class Ducato : public Truck {
public:
	std::string getName() const override 
	{
		return " Ducato ";
	}
	std::string getManufacturer() const override 
	{
		return " Fiat ";
	}

	// ... constructor (you can make what you need)
	Ducato() = default;						// default constructor
	Ducato(const Ducato& ducato) = delete;				// copy constructor
	Ducato operator=(const Ducato& ducato) = delete;		// copy assignment operator
	Ducato(Ducato&& ducato) = delete;				// move constructor
	Ducato operator=(Ducato&& ducato) = delete;			// move assignment operator
	~Ducato() {}							// destructor
};

/*
* Abstract Factory
* provides an abstract interface for creating a family of products
*/
class AbstractFactory {
public:
	virtual std::unique_ptr<Car> createCar() = 0;		// virtual ProductA *createProductA() = 0;
	virtual std::unique_ptr<Truck> createTruck() = 0;	// virtual ProductB *createProductB() = 0;

	// ... constructor (you can make what you need)
	AbstractFactory() = default;							// default constructor
	AbstractFactory(const AbstractFactory& abstractFactory) = delete;		// copy constructor
	AbstractFactory(AbstractFactory&& abstractFactory) = delete;			// move constructor
	virtual ~AbstractFactory() {}							// destructor
};

/*
* Concrete Factory French
* each concrete factory create a family of products and client uses
* one of these factories so it never has to instantiate a product object
*/
class ConcreteFactoryFrench : public AbstractFactory {
public:
	std::unique_ptr<Car> createCar() override 
	{
		return std::make_unique<Kangoo>();
	}
	std::unique_ptr<Truck> createTruck() override 
	{
		return std::make_unique<Maxity>();
	}

	// ... constructor (you can make what you need)
	ConcreteFactoryFrench() = default;								// default constructor
	ConcreteFactoryFrench(const ConcreteFactoryFrench& concreteFactoryFrench) = delete;		// copy constructor
	ConcreteFactoryFrench operator=(const ConcreteFactoryFrench& concreteFactoryFrench) = delete;	// copy assignment operator
	ConcreteFactoryFrench(ConcreteFactoryFrench&& concreteFactoryFrench) = delete;			// move constructor
	ConcreteFactoryFrench operator=(ConcreteFactoryFrench&& concreteFactoryFrench) = delete;	// move assignment operator
	~ConcreteFactoryFrench() {}									// destructor
};

/*
* Concrete Factory Italian
* each concrete factory create a family of products and client uses
* one of these factories so it never has to instantiate a product object
*/
class ConcreteFactoryItalian : public AbstractFactory {
public:
	std::unique_ptr<Car> createCar() override 
	{
		return std::make_unique<Cinquecento>();
	}
	std::unique_ptr<Truck> createTruck() override 
	{
		return std::make_unique<Ducato>();
	}

	// ... constructor (you can make what you need)
	ConcreteFactoryItalian() = default;									// default constructor
	ConcreteFactoryItalian(const ConcreteFactoryItalian& concreteFactoryItalian) = delete;			// copy constructor
	ConcreteFactoryItalian operator=(const ConcreteFactoryItalian& concreteFactoryItalian) = delete;	// copy assignment operator
	ConcreteFactoryItalian(ConcreteFactoryItalian&& concreteFactoryItalian) = delete;			// move constructor
	ConcreteFactoryItalian operator=(ConcreteFactoryItalian&& concreteFactoryItalian) = delete;		// move assignment operator
	~ConcreteFactoryItalian() {}										// destructor
};

/*
* example use of AbstractFactory
*/
void application(AbstractFactory& factory) 
{
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

	std::shared_ptr<ConcreteFactoryFrench> factoryFrench_ptr = std::make_shared<ConcreteFactoryFrench>();
	std::shared_ptr<ConcreteFactoryItalian> factoryItalian_ptr = std::make_shared<ConcreteFactoryItalian>();
	std::unique_ptr<Car> car1 = factoryFrench_ptr->createCar();
	std::cout << "Product car1: " << car1->getName() << std::endl;
	std::unique_ptr<Car> car2 = factoryItalian_ptr->createCar();
	std::cout << "Product car2 : " << car2->getName() << std::endl;

	system("pause");
	return 0;
}
