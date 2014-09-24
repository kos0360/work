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

Link* Link::add(Link* nl)
{
    if(nl==0) return this;
    if(succ!=0) nl->succ=succ;
    succ=nl;
    return nl;
}

void print_all(Link* p)
{
    while(p){
        cout << p->value << " ";
        p=p->next();
    }
}



int main()
{
    
    Link* w= new Link("What");
    Link* next=begin->add(new Link("is"));
    
    print_all(begin);    
    
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
}
