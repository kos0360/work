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
    Link* next() const {return succ;}
    
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

Link* Link::find(const string& v)
{
    Link* p=this;
    while(p){
        if(p->value==v) return p;
        p=p->next();
    }
    return 0;
}

void print_all(const Link* p)
{
    while(p){
        cout << p->value << " ";
        p=p->next();
    }
}

int main()
{
    
    Link* begin= new Link("What");
    Link* next=begin->add(new Link("is"));
    next=next->add(new Link("your"));
    next=next->add(new Link("name________"));
    
    Link* f=begin->find("is");
    if(f) cout << f->value << endl;
    
    
    print_all(begin);
    
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
}
