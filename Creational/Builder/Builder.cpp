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
* Car  ==>  Product
* the final object that will be created using Builder
*/
class Car {
public:
	void makeSeat(const std::string &part) 
	{
		partSeat = part;
	}
	void makeEngine(const std::string &part) 
	{
		partEngine = part;
}
	void makeWheel(const std::string &part) 
	{
		partWheel = part;
	}

	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Car> &car)
	{
		return out << " Seat : " << car->partSeat << " , Engine : " << car->partEngine << " and Wheel : " << car->partWheel;
	}

	// ... constructor (you can make what you need)
	Car() = default;					// default constructor
	Car(const Car& car) = delete;				// copy constructor
	Car operator=(const Car& car) = delete;			// copy assignment operator
	Car(const Car&& car) = delete;				// move constructor
	Car operator=(Car&& car) = delete;			// move assignment operator
	~Car() {}						// destructor

private:
	std::string partSeat;
	std::string partEngine;
	std::string partWheel;
	// ...
};

/*
* Builder
* abstract interface for creating products
*/
class Builder {
public:

	virtual void buildPartSeat(const std::unique_ptr<Car> &car) = 0;
	virtual void buildPartEngine(const std::unique_ptr<Car> &car) = 0;
	virtual void buildPartWheel(const std::unique_ptr<Car> &car) = 0;

	// ... constructor (you can make what you need)
	Builder() = default;					// default constructor
	Builder(const Builder& builder) = delete;		// copy constructor
	Builder(Builder&& builder) = delete;			// move constructor
	virtual ~Builder() {}					// destructor
};

/*
* Concrete Builder Luxury
* create real products and stores them in the composite structure
*/
class ConcreteBuilderLuxury : public Builder {
public:
	void buildPartSeat(const std::unique_ptr<Car> &car) override 
	{
		car->makeSeat("Luxury Seat");
	}
	void buildPartEngine(const std::unique_ptr<Car> &car) override 
	{
		car->makeEngine("Luxury Engine");
	}
	void buildPartWheel(const std::unique_ptr<Car> &car) override 
	{
		car->makeWheel("Luxury Wheel");
	}

	// ... constructor (you can make what you need)
	ConcreteBuilderLuxury() = default;								// default constructor
	ConcreteBuilderLuxury(const ConcreteBuilderLuxury& concreteBuilderLuxury) = delete;		// copy constructor
	ConcreteBuilderLuxury operator=(const ConcreteBuilderLuxury& concreteBuilderLuxury) = delete;	// copy assignment operator
	ConcreteBuilderLuxury(ConcreteBuilderLuxury&& concreteBuilderLuxury) = delete;			// move constructor
	ConcreteBuilderLuxury operator=(ConcreteBuilderLuxury&& concreteBuilderLuxury) = delete;	// move assignment operator
	~ConcreteBuilderLuxury() {}									// destructor
};

/*
* Concrete Builder Basic
* create real products and stores them in the composite structure
*/
class ConcreteBuilderBasic : public Builder {
public:
	void buildPartSeat(const std::unique_ptr<Car> &car) override 
	{
		car->makeSeat("Basic Seat");
	}
	void buildPartEngine(const std::unique_ptr<Car> &car) override 
	{
		car->makeEngine("Basic Engine");
	}
	void buildPartWheel(const std::unique_ptr<Car> &car) override 
	{
		car->makeWheel("Basic Wheel");
	}

	// ... constructor (you can make what you need)
	ConcreteBuilderBasic() = default;								// default constructor
	ConcreteBuilderBasic(const ConcreteBuilderBasic& concreteBuilderBasic) = delete;		// copy constructor
	ConcreteBuilderBasic operator=(const ConcreteBuilderBasic& concreteBuilderBasic) = delete;	// copy assignment operator
	ConcreteBuilderBasic(ConcreteBuilderBasic&& concreteBuilderBasic) = delete;			// move constructor
	ConcreteBuilderBasic operator=(ConcreteBuilderBasic&& concreteBuilderBasic) = delete;		// move assignment operator
	~ConcreteBuilderBasic() {}									// destructor
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


	std::unique_ptr<Car> construct() 
	{
		std::unique_ptr<Car> car = std::make_unique<Car>();
		builder_ptr.lock()->buildPartSeat(car);
		builder_ptr.lock()->buildPartEngine(car);
		builder_ptr.lock()->buildPartWheel(car);
		return car;
		// ...
	}

	// ... constructor (you can make what you need)
	Director(const Director& director) = delete;				// copy constructor
	Director operator=(const Director& director) = delete;			// copy assignment operator
	Director(Director&& director) = delete;					// move constructor
	Director operator=(Director&& director) = delete;			// move assignment operator
	~Director() {}								// destructor

private:
	std::weak_ptr<Builder> builder_ptr;
};

int main()
{
	std::shared_ptr<Builder> concreteBuilderLuxury = std::make_shared<ConcreteBuilderLuxury>();
	Director director(concreteBuilderLuxury);
	std::unique_ptr<Car> carLuxury = director.construct();
	std::cout << "Product car1 " << carLuxury << std::endl;

	std::shared_ptr<Builder> concreteBuilderBasic = std::make_shared<ConcreteBuilderBasic>();
	director.set(concreteBuilderBasic);
	std::unique_ptr<Car> carBasic = director.construct();
	std::cout << "Product car2 " << carBasic << std::endl;

	system("pause");
	return 0;
}
