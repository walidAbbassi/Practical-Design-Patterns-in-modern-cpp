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
* Drink  ==>  Component
* defines an interface for objects that can have responsibilities
* added to them dynamically
*/
class Drink {
public:
	virtual std::string toString() const = 0;
	virtual unsigned int getPrice() const = 0;
	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Drink> &drink)
	{
		return out << " [Component] : " << drink->toString();
	}
	virtual ~Drink(){}
};

/*
* Water  ==>  Concrete Component
* defines an object to which additional responsibilities
* can be attached
*/
class Water : public Drink {
public:
	std::string toString() const override {return " Water ";}
	unsigned int getPrice() const override { return 1; }
	~Water() {}
};

/*
* Milk  ==>  Concrete Component
* defines an object to which additional responsibilities
* can be attached
*/
class Milk : public Drink {
public:
	std::string toString() const override { return " Milk "; }
	unsigned int getPrice() const override { return 10; }
	~Milk() {}
};

/*
* Ingredient  ==>  Decorator
* maintains a reference to a Component object and defines an interface
* that conforms to Component's interface
*/
class Ingredient : public Drink {
public:
	explicit Ingredient(std::unique_ptr<Drink> drink)
		: drink(std::move(drink)) {}

	virtual std::string toString()  const override
	{
		return drink->toString();
	}
	virtual unsigned int getPrice()  const override
	{
		return drink->getPrice();
	}
	virtual ~Ingredient() {}

private:
	std::unique_ptr<Drink> drink;
};

/*
* Coffee  ==>  Concrete Decorators
* add responsibilities to the component (can extend the state
* of the component)
*/
class Coffee : public Ingredient {
public:
	explicit Coffee(std::unique_ptr<Drink> drink)
		: Ingredient(std::move(drink)) {}

	std::string toString() const override
	{
		return Ingredient::toString()+"+ Coffee ";
	}

	unsigned int getPrice()  const override
	{
		return Ingredient::getPrice() + 5;
	}

	~Coffee() {}
};


/*
* Sugar  ==>  Concrete Decorators
* add responsibilities to the component (can extend the state
* of the component)
*/
class Sugar : public Ingredient {
public:
	explicit Sugar(std::unique_ptr<Drink> drink)
		: Ingredient(std::move(drink)) {}

	std::string toString() const override
	{
		return Ingredient::toString() + "+ Sugar ";
	}

	unsigned int getPrice() const override
	{
		return Ingredient::getPrice() + 1;
	}

	~Sugar() {}
};

/*
* ice Cube  ==>  Concrete Decorators
* add responsibilities to the component (can extend the state
* of the component)
*/
class IceCube : public Ingredient {
public:
	explicit IceCube(std::unique_ptr<Drink> drink)
		: Ingredient(std::move(drink)) {}

	std::string toString() const override
	{
		return Ingredient::toString() + "+ Ice Cube ";
	}

	unsigned int getPrice() const override
	{
		return Ingredient::getPrice() + 1;
	}

	~IceCube() {}
};


int main()
{
	std::unique_ptr<Drink> icedCoffee = std::make_unique<Coffee>(std::make_unique<IceCube>
								(std::make_unique<Sugar>
								(std::make_unique<Water>())));
	std::cout << "recipe of Iced Coffee " << icedCoffee << std::endl;
	std::cout << "price : " << icedCoffee->getPrice() <<" $"<< std::endl;

	std::unique_ptr<Drink> cafeLatte = std::make_unique<Coffee>(std::make_unique<Sugar>
								   (std::make_unique<Milk>()));
	std::cout << "recipe of Cafe Latte " << cafeLatte << std::endl;
	std::cout << "price : " << cafeLatte->getPrice() << " $" << std::endl;

	system("pause");
	return 0;
}
