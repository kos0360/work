// Example program
#include <iostream>
#include <string>

using namespace std;

struct Link
{
    Link(const string& v)
    : value(v), succ(0){}

    Link* add(Link*);
    Link* add_ordered(Link*);
    Link* find(const string& v);
    const Link* find(const string& v) const;
    Link* next();
    
    string value;
    Link* succ;
};



int main()
{
    
    Link* w= new Link("What");
    
    
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
}
