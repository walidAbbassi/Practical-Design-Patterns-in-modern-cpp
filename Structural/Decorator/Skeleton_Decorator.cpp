/*
* C++ Design Patterns: Decorator
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <string>
#include <memory>

/*
* Component
* defines an interface for objects that can have responsibilities
* added to them dynamically
*/
class Component {
public:
	virtual std::string toString() const = 0;
	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Component> &component)
	{
		return out << " [Component] : " << component->toString();
	}
	virtual ~Component() {}
};

/*
* Concrete Component A
* defines an object to which additional responsibilities
* can be attached
*/
class ConcreteComponent_A : public Component {
public:
	std::string toString() const override { return " ConcreteComponent_A "; }
	~ConcreteComponent_A() {}
};

/*
* Concrete Component B
* defines an object to which additional responsibilities
* can be attached
*/
class ConcreteComponent_B : public Component {
public:
	std::string toString() const override { return " ConcreteComponent_B "; }
	~ConcreteComponent_B() {}
};

/*
* Decorator
* maintains a reference to a Component object and defines an interface
* that conforms to Component's interface
*/
class Decorator : public Component {
public:
	explicit Decorator(std::unique_ptr<Component> component)
		: component(std::move(component)) {}

	virtual std::string toString()  const override
	{
		return component->toString();
	}
	virtual ~Decorator() {}

private:
	std::unique_ptr<Component> component;
};

/*
* Concrete Decorators A
* add responsibilities to the component (can extend the state
* of the component)
*/
class ConcreteDecorators_A : public Decorator {
public:
	explicit ConcreteDecorators_A(std::unique_ptr<Component> component)
		: Decorator(std::move(component)) {}

	std::string toString() const override
	{
		return Decorator::toString() + "+ ConcreteDecorators_A ";
	}

	~ConcreteDecorators_A() {}
};


/*
* Concrete Decorators B
* add responsibilities to the component (can extend the state
* of the component)
*/
class ConcreteDecorators_B : public Decorator {
public:
	explicit ConcreteDecorators_B(std::unique_ptr<Component> Component)
		: Decorator(std::move(Component)) {}

	std::string toString() const override
	{
		return Decorator::toString() + "+ ConcreteDecorators_B ";
	}

	~ConcreteDecorators_B() {}
};

/*
* Concrete Decorators C
* add responsibilities to the component (can extend the state
* of the component)
*/
class ConcreteDecorators_C : public Decorator {
public:
	explicit ConcreteDecorators_C(std::unique_ptr<Component> Component)
		: Decorator(std::move(Component)) {}

	std::string toString() const override
	{
		return Decorator::toString() + "+ ConcreteDecorators_C ";
	}

	~ConcreteDecorators_C() {}
};


int main()
{
	std::unique_ptr<Component> component_1 = std::make_unique<ConcreteDecorators_A>
								(std::make_unique<ConcreteDecorators_C>
								(std::make_unique<ConcreteDecorators_B>
								(std::make_unique<ConcreteComponent_A>())));
	std::cout << "recipe of component_1 " << component_1 << std::endl;

	std::unique_ptr<Component> component_2 = std::make_unique<ConcreteDecorators_A>
								(std::make_unique<ConcreteDecorators_B>
								(std::make_unique<ConcreteComponent_B>()));
	std::cout << "recipe of component_2 " << component_2 << std::endl;

	system("pause");
	return 0;
}
