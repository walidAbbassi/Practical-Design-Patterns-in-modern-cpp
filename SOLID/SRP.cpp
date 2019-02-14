#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//using namespace std;

// SRP
// Single responsibility principle
// module, class, or function should have responsibility over a single part of the functionality

class Journal
{
    //move function save file from class Journal to other class PersistenceManager
    private:
    std::string title_;
    std::vector<std::string> entries_;
    public:
    Journal(const std::string &title):title_(title){}
    void add(const std::string& entrie)
	{
        entries_.emplace_back(entrie);
    }
    std::vector<std::string> getEntries() const { return this->entries_;}
    std::string getTitle() const { return this->title_;}
};

class PersistenceManager
{
    public:
    static void save(const Journal& journal, const std::string& filename)
    {
        std::ofstream file(filename);
        for(const auto& entrie:journal.getEntries())
        {
            file<<entrie<<std::endl;    
		}
    }
    
};


int main() {
	Journal journal("C++ SOLID");
	journal.add("Single responsibility principle");
	journal.add("Open–closed principle");
	journal.add("Liskov substitution principle");
	journal.add("Interface segregation principle");
	journal.add("Dependency inversion principle");
	PersistenceManager::save(journal, "SOLID");
}
