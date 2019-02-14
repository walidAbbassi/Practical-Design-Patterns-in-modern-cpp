#include <iostream>
#include <string>
#include <vector>

//using namespace std;

// ISP
// Interface segregation principle
// no client should be forced to depend on methods it does not use (splits interfaces)

class Document
{
    private:
    std::string name_;
    std::string type_;
    public:
    Document(const std::string &name,const std::string &type):name_(name), type_(type){}
    std::string getName() const { return this->name_;}
    std::string getType() const { return this->type_;}
};

// for client(bad idea) ==> splits interfaces
// class Imachine{
//   public:
//   virtual void print(std::vector<Document*> document) = 0;
//   virtual void scan(std::vector<Document*> document) = 0;
//   virtual void fax(std::vector<Document*> document) = 0;
// };

// class MachineFunction : public Imachine
// {
//   public:
//   void print(std::vector<Document*> document) override;
//   void scan(std::vector<Document*> document) override;
//   void fax(std::vector<Document*> document) override;
// };


// splits interfaces
class Iprinter
{
    public:
    virtual void print(std::vector<Document*> document) = 0;
};

class Iscaner
{
    public:
    virtual void scan(std::vector<Document*> document) = 0;
};

class Ifaxer
{
    public:
    virtual void fax(std::vector<Document*> document) = 0;
};


class Printer : public Iprinter
{
    public:
    void print(std::vector<Document*> document) override;
};

class Scaner : public Iscaner
{
    public:
    void scan(std::vector<Document*> document) override;
};

class Faxer : public Ifaxer
{
    public:
    void fax(std::vector<Document*> document) override;
};

class Imachine : public Iprinter, public Iscaner, public Ifaxer
{
    //other virtual fonction ....
};

class Machine : public Imachine
{
    private:
    Iprinter& printer_;
    Iscaner& scaner_;
    Ifaxer& faxer_;
    
    public:
    Machine(Iprinter& printer, Iscaner& scaner, Ifaxer& faxer):printer_(printer), scaner_(scaner), faxer_(faxer){}
    void print(std::vector<Document*> document) override
    {
        // proxy design
        printer_.print(document);
    }
    
    void scan(std::vector<Document*> document) override
    {
        // proxy design
        scaner_.scan(document);
    }
    
    void fax(std::vector<Document*> document) override
    {
        // proxy design
        faxer_.fax(document);
    }
};

int main() {

}
