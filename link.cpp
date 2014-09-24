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
	Link* erase(Link*);
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

Link* Link::add_ordered(Link* nl) // ������ ���������� ��������� �� ������ ������
{
    if(value>nl->value){ // ���� ����� ���� ����������
        nl->succ=this;
        return nl;
    }
    Link* p=this;    
    while(p){
        if(p->next()==0 || p->next()->value>=nl->value){
            p->add(nl);
            return this;
        }
        p=p->next();
    }
    return this; // �� ��������
}

Link* Link::erase(Link* ep) // ���������� �� ������� ��������, ���������� ��������� �� ������ �������
{
    Link* p=this;
    Link* prev=0;
    while(p){
        if(ep==p && prev==0) // ��������� �������� ������ �����
            return succ;
        if(ep==p && prev!=0){ // ��������� �� �������� ������ �����
            prev->succ=p->succ;
            return this;
        }
        prev=p;
        p=p->next();
    }
    return this;
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
    /*
    Link* begin= new Link("What");
    Link* next=begin->add(new Link("is"));
    next=next->add(new Link("your"));
    next=next->add(new Link("name________"));
    */

	Link* begin= new Link("b");
    begin=begin->add_ordered(new Link("a"));
    begin=begin->add_ordered(new Link("d"));
    begin=begin->add_ordered(new Link("c"));
    begin=begin->add_ordered(new Link("f"));
    begin=begin->add_ordered(new Link("a"));
    begin=begin->add_ordered(new Link("e"));


    Link* f=begin->find("is");
    if(f){
        cout << f->value << endl;
        begin=begin->erase(f);
    }
    
    
    print_all(begin);
    
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
}
