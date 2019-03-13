/*
* C++ Design Patterns: Composite
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <functional> 
#include <memory>

/*
* Component
* defines an interface for all objects in the composition
* both the composite and the leaf nodes
*/
class Component {
public:

	virtual void add(const std::weak_ptr<Component> &component) { /* ... */ }

	virtual void display() const = 0;
	virtual ~Component() {}
};

/*
* Composite
* defines behavior of the components having children
* and store child components
*/
class Composite : public Component {
public:

	Composite() = default;

	void add(const std::weak_ptr<Component> &component)
	{
		if (!component.expired())
		{
			children.push_back(component);
		}		
	}

	void display() const override
	{
		std::cout << " (";
		//for_each(children.begin(), children.end(), std::mem_fun(&Component::display));  ==> old if you use raw pointer in your project
		for_each(children.begin(), children.end(), [=](std::weak_ptr<Component> component) {if (!component.expired()) { component.lock()->display(); } });
		std::cout << ") ";

	}

	~Composite() {}

private:
	std::vector<std::weak_ptr<Component>> children;
};

/*
* Leaf
* defines the behavior for the elements in the composition,
* it has no children
*/
class Leaf : public Component {
public:
	Leaf(const std::string& name) : name(name) {}

	void display() const override
	{
		std::cout << "[" << name << "]";
	}

	std::string getName() const { return name; }

	~Leaf() {}

private:
	std::string name;
};


int main()
{
	std::shared_ptr<Composite> group_1 = std::make_shared<Composite>();
	std::shared_ptr<Composite> group_2 = std::make_shared<Composite>();
	std::shared_ptr<Composite> group_3 = std::make_shared<Composite>();
	std::shared_ptr<Leaf> leaf_1 = std::make_shared<Leaf>("Leaf_1");
	std::shared_ptr<Leaf> leaf_2 = std::make_shared<Leaf>("Leaf_2");
	std::shared_ptr<Leaf> leaf_3 = std::make_shared<Leaf>("Leaf_3");
	std::shared_ptr<Leaf> leaf_4 = std::make_shared<Leaf>("Leaf_4");
	std::shared_ptr<Leaf> leaf_5 = std::make_shared<Leaf>("Leaf_5");

	group_1->add(leaf_1);
	group_1->add(group_2);

	group_2->add(leaf_2);
	group_2->add(leaf_3);

	group_3->add(leaf_4);

	group_2->add(group_3);

	group_1->display();
	std::cout << "\n";

	group_2->display();
	std::cout << "\n";

	group_3->display();
	std::cout << "\n";

	leaf_5->display();
	std::cout << "\n";

	system("pause");
	return 0;
}
