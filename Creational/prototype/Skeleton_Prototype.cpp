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
* Prototype
* declares an interface for cloning itself
*/
class Prototype {
public:
	virtual std::unique_ptr<Prototype> clone() = 0;
	virtual std::string getType() const = 0;
	virtual ~Prototype() {}
	// ...
};

/*
* Concrete Prototype X
* implement an operation for cloning itself
*/
class ConcretePrototype_X : public Prototype {
public:
	std::unique_ptr<Prototype> clone() override
	{
		return std::make_unique<ConcretePrototype_X>(*this);
	}
	std::string getType() const override
	{
		return " type X ";
	}
	// ...
};

/*
* Concrete Prototype Y
* implement an operation for cloning itself
*/
class ConcretePrototype_Y : public Prototype {
public:
	std::unique_ptr<Prototype> clone() override
	{
		return std::make_unique<ConcretePrototype_Y>(*this);
	}
	std::string getType() const override
	{
		return " type Y ";
	}
	// ...
};

/*
* Client
* creates a new object by asking a prototype to clone itself
*/
class ClientCrazyScientist {
public:
	static std::shared_ptr<Prototype> cloningMachine(const std::shared_ptr<Prototype>& prototype)
	{
		return prototype->clone();
	}
	// ...

};


int main()
{
	static std::shared_ptr<ConcretePrototype_X> prototype_X = std::make_shared<ConcretePrototype_X>();
	std::shared_ptr<Prototype> prototype = ClientCrazyScientist::cloningMachine(prototype_X);
	std::cout << "Prototype cloned : " << prototype->getType() << std::endl;

	system("pause");
	return 0;
}
