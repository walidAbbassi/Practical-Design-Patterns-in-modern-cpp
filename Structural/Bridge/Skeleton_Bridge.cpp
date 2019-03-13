/*
* C++ Design Patterns: Bridge
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <memory>

/*
* Implementor
* defines the interface for implementation classes
*/
class Implementor {
public:
	virtual void operationImpl(const double& side) = 0;
	virtual ~Implementor(){}
	// ...
};

/*
* Concrete Implementors A
* implement the Implementor interface and define concrete implementations
*/
class ConcreteImplementors_A : public Implementor {
public:
	void operationImpl(const double& side) override
	{
		std::cout << "Concrete Implementor A " << std::endl;
	}
	~ConcreteImplementors_A() {}
	// ...
};

/*
* Concrete Implementors B
* implement the Implementor interface and define concrete implementations
*/
class ConcreteImplementors_B : public Implementor {
public:
	void operationImpl(const double& side) override
	{
		std::cout << "Concrete Implementor B " << std::endl;
	}
	~ConcreteImplementors_B() {}
	// ...
};

/*
* Abstraction
* defines the abstraction's interface
*/
class Abstraction {
public:
	virtual void operation() = 0; // low-level
	virtual void action(const double& size) = 0; // high-level
	virtual ~Abstraction() {}
protected:
	std::weak_ptr<Implementor> implementor_ptr;
	Abstraction(const std::weak_ptr<Implementor> &implementor) : implementor_ptr(implementor) {}
	// ...
};

/*
* RefinedAbstraction
* extends the interface defined by Abstraction
*/
class RefinedAbstraction : public Abstraction {
public:
	RefinedAbstraction(const double& side, const std::shared_ptr<Implementor> &implementor)
		: side(side), Abstraction(implementor) {}

	//	 low-level i.e. Implementation specific
	void operation() override
	{
		implementor_ptr.lock()->operationImpl(side);
	}

	//	 high-level i.e. Abstraction specific
	void action(const double& size) override
	{
		std::cout << "action  " << std::endl;
		side *= size;
	}

	~RefinedAbstraction() {}
	// ...

private:
	double side;
	double size;
};



int main()
{
	std::shared_ptr<Implementor> implementor_A = std::make_shared<ConcreteImplementors_A>();
	std::shared_ptr<Implementor> implementor_B = std::make_shared<ConcreteImplementors_B>();

	std::shared_ptr<Abstraction> abstraction = std::make_shared<RefinedAbstraction>(5, implementor_A);
	abstraction->operation();
	abstraction->action(2);
	abstraction->operation();

	abstraction = std::make_shared<RefinedAbstraction>(10, implementor_B);
	abstraction->operation();

	system("pause");
	return 0;
}
