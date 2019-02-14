#include <iostream>
#include <string>
#include <vector>

//using namespace std;

// OCP
// Open–closed principle
// (classes, modules, functions, etc.) should be open for extension, but closed for modification
// Open-closed principle is one of the five SOLID principles of object-oriented design.

enum class Color {RED, GREEN, BLUE};
enum class Size {SMALL, MEDIUM, LARGE};

class Product
{
  private:
  std::string name_;
  Color color_;
  Size size_;
  public:
  Product(std::string name, Color color,Size size):name_(name), color_(color), size_(size){}
  const std::string& getName() const {return this->name_;}
  const Color& getColor() const {return this->color_;}
  const Size& getSize() const {return this->size_;}
  void print()const{std::cout<< " name = "<< this->name_ <<std::endl;}
  /*
  ...
  */
};

// abstract class pure
template <typename T>
class Ispecification{
  public:
  virtual bool is_satisfied(T* item) = 0;
};

class ColorSpecification : public Ispecification<Product>
{
  private:
  Color color_;
    
  public:
  explicit ColorSpecification(const Color color):color_(color){}
  bool is_satisfied(Product *product) override {return product->getColor() == this->color_;}
};

class SizeSpecification : public Ispecification<Product>
{
  private:
  Size size_;
    
  public:
  explicit SizeSpecification(const Size size):size_(size){}
  bool is_satisfied(Product *product) override{return product->getSize() == this->size_;}
};

template<typename T>
class And_Specification: public Ispecification<T>
{
    private:
    Ispecification<T>& first_;
    Ispecification<T>& second_;
    
    public:
    And_Specification(Ispecification<T>& first, Ispecification<T>& second):first_(first), second_(second){}
    bool is_satisfied(T *product) override{ return first_.is_satisfied(product) && second_.is_satisfied(product);}
    
};

template<typename T>
class Or_Specification: public Ispecification<T>
{
    private:
    Ispecification<T>& first_;
    Ispecification<T>& second_;
    
    public:
    Or_Specification(Ispecification<T>& first, Ispecification<T>& second):first_(first), second_(second){}
    bool is_satisfied(T *product) override{ return first_.is_satisfied(product) || second_.is_satisfied(product);}
    
};

/*              ==========================================================================================              */


// abstract class pure
template <typename T>
class Ifilter
{
  public:
  virtual std::vector<T*> filter(std::vector<T*> items, Ispecification<T> &spec)=0;
};

class ProductFilter : public Ifilter<Product>
{
    public:
    std::vector<Product*> filter(std::vector<Product*> items, Ispecification<Product> &spec) override
    {
        std::vector<Product*> results;
        for(const auto &item: items)
        {
            if(spec.is_satisfied(item))
            {
                results.emplace_back(item);
            }
        }
        return results;
    }
};



int main() {
	Product apple("Apple", Color::GREEN, Size::MEDIUM);
	Product tree("Tree", Color::GREEN, Size::LARGE);
	Product house("House", Color::BLUE, Size::LARGE);
	
	std::vector<Product*> all_product = {&apple,&tree,&house};
	ProductFilter productFilter;
	
	ColorSpecification green(Color::GREEN);
	auto productGreens = productFilter.filter(all_product, green);
	// show result 
	std::cout<< "Green product : "<<std::endl;
	for(const auto& productGreen :productGreens)
	{
	    productGreen->print();
	}
	
	SizeSpecification large(Size::LARGE);
	auto productLarges = productFilter.filter(all_product, large);
	// show result 
	std::cout<< "Large product : "<<std::endl;
	for(const auto& productLarge :productLarges)
	{
	    productLarge->print();
	}
	
	And_Specification<Product> green_and_large(green,large);
	auto product_green_and_larges = productFilter.filter(all_product, green_and_large);
	// show result 
	std::cout<< "green and large product : "<<std::endl;
	for(const auto& product_green_and_large :product_green_and_larges)
	{
	    product_green_and_large->print();
	}
	
	Or_Specification<Product> green_or_large(green,large);
	auto product_green_or_larges = productFilter.filter(all_product, green_or_large);
	// show result 
	std::cout<< "green or large product : "<<std::endl;
	for(const auto& product_green_or_large :product_green_or_larges)
	{
	    product_green_or_large->print();
	}
	
	system("pause");
	
}
