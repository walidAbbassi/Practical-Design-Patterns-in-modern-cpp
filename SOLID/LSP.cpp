#include <iostream>
#include <string>
#include <vector>

//using namespace std;

// LSP
// Liskov substitution principle
// Liskov's notion of a behavioural subtype defines a notion of substitutability for objects; that is, if S is a subtype of T, 
// then objects of type T in a program may be replaced with objects of type S without altering any of the desirable properties of that program

class Rectangle
{
    private:
    double height_;
    double width_;
    public:
    Rectangle(double height, double width):height_(height), width_(width){}
    virtual void SetHeight(double height){height_ = height;}
    virtual void SetWidth(double width) {width_ = width;}
    double GetHeight() const {return this->height_;}
    double GetWidth() const {return this->width_;}
    double getArea(){return width_ * height_;}
};

class Square : public Rectangle
{
    public:
    Square(double width):Rectangle(width,width){}
    virtual void SetWidth(double width)
    {
        Rectangle::SetWidth(width);
        Rectangle::SetHeight(width);
    }
    
    virtual void SetHeight(double height)
    {
        Rectangle::SetHeight(height);
        Rectangle::SetWidth(height);
    }
};

void process(Rectangle& rectangle)
{
    double width = rectangle.GetWidth();
    rectangle.SetHeight(10);
    std::cout<< "area expect = "<<(10 * width) << " get result area = "<<rectangle.getArea()<<std::endl;
}

int main() {
    
    Rectangle rectangle(5,5);
    process(rectangle);
    Square square(5);
    process(square); // we got problem because LSP is not respected
    //This principle is just an extension of the Open Close Principle and it means that 
	//we must make sure that new derived classes are extending the base classes without changing their behavior.
}
