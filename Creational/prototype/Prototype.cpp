/*
* C++ Design Patterns: Prototype
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
* Animal  ==>  Prototype
* declares an interface for cloning itself
*/
class PrototypeAnimal {
public:
	virtual std::unique_ptr<PrototypeAnimal> clone() = 0;
	virtual std::string getType() const = 0;
	virtual ~PrototypeAnimal() {}					// destructor
	// ...
};

/*
* Concrete Prototype Sheep
* implement an operation for cloning itself
*/
class ConcretePrototypeSheep : public PrototypeAnimal {
public:
	std::unique_ptr<PrototypeAnimal> clone() override
	{
		return std::make_unique<ConcretePrototypeSheep>(*this);
	}
	std::string getType() const override 
	{
		return " Sheep ";
	}
	// ...
};

/*
* Concrete Prototype Mouse
* implement an operation for cloning itself
*/
class ConcretePrototypeMouse : public PrototypeAnimal {
public:
	std::unique_ptr<PrototypeAnimal > clone() override 
	{
		return std::make_unique<ConcretePrototypeMouse>(*this);
	}
	std::string getType() const override 
	{
		return " Mouse ";
	}
	// ...
};

/*
* Client
* creates a new object by asking a prototype to clone itself
*/
class ClientCrazyScientist {
public:
	static std::shared_ptr<PrototypeAnimal> cloningMachine(const std::shared_ptr<PrototypeAnimal>& prototypeAnimal) 
	{
		return prototypeAnimal->clone();
	}
	// ...

};


int main()
{
	static std::shared_ptr<ConcretePrototypeSheep> Sheep = std::make_shared<ConcretePrototypeSheep>();
	std::shared_ptr<PrototypeAnimal> animal = ClientCrazyScientist::cloningMachine(Sheep);
	std::cout << "Prototype animal : " << animal->getType() << std::endl;

	system("pause");
	return 0;
}
