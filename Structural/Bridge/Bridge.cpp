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
* Drawing  ==>  Implementor
* defines the interface for implementation classes
*/
class Drawing {
public:
	virtual void drawSquare(const double& side) = 0;
	// ...
};

/*
* DrawingSquarePencil  ==>  Concrete Implementors A 
* implement the Implementor interface and define concrete implementations
*/
class DrawingSquareWithPencil : public Drawing {
public:
	void drawSquare(const double& side) override
	{
		// use your function or use framework to draw : 
		// openFrameworks(https://github.com/openframeworks/openFrameworks) /opencv/Qt/openGL ...
		std::cout << "Concrete Implementor A draw Square with Pencil " << std::endl;
	}
	// ...
};

/*
* DrawingRectangle  ==>  Concrete Implementors B
* implement the Implementor interface and define concrete implementations
*/
class DrawingSquareWithBrush : public Drawing {
public:
	void drawSquare(const double& side) override
	{
		// use your function or use framework to draw : 
		// openFrameworks(https://github.com/openframeworks/openFrameworks) /opencv/Qt/openGL ...
		std::cout << "Concrete Implementor B draw Square with Brush " << std::endl;
	}
	// ...
};

/*
* Shape  ==>  Abstraction
* defines the abstraction's interface
*/
class Shape {
public:
	virtual void draw() = 0; // low-level
	virtual void resize(const double& size) = 0; // high-level
	virtual ~Shape() {
	}
protected:
	std::weak_ptr<Drawing> drawing;
	Shape(const std::weak_ptr<Drawing> &drawing) : drawing(drawing) {}
	// ...
};

/*
* Square  ==>  RefinedAbstraction
* extends the interface defined by Abstraction
*/
class Square : public Shape {
public:
	Square(double side, const std::shared_ptr<Drawing> &drawingImplementor)
		: side(side), Shape(drawingImplementor) {}

//	 low-level i.e. Implementation specific
	void draw() override 
	{
		drawing.lock()->drawSquare(side);
	}

//	 high-level i.e. Abstraction specific
	void resize(const double& size) override
	{
		std::cout << "Resize Square with = " << size << std::endl;
		side *= size;
	}

	~Square() {}
	// ...

private:
	double side;
	double size;
};



int main()
{
	std::shared_ptr<Drawing> drawBrush = std::make_shared<DrawingSquareWithBrush>();
	std::shared_ptr<Drawing> drawPencil = std::make_shared<DrawingSquareWithPencil>();

	std::shared_ptr<Shape> square = std::make_shared<Square>(5, drawBrush);
	square->draw();
	square->resize(2);
	square->draw();

	square = std::make_shared<Square>(10, drawPencil);
	square->draw();

	system("pause");
	return 0;
}
