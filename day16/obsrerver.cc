#include<stdlib.h>
#include<time.h>

#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<memory>
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::unique_ptr;


class Observer
{
public:
    virtual void update()=0;
    virtual ~Observer(){cout<<"~Observer()"<<endl;}
};

class Baby
:public Observer
{
public:
    Baby(const char* s)
    :_name(s)
    {

    }
    void update();
private:
    string _name;
};

void Baby::update()
{
    ::srand(::clock());
    int num=::rand()%100;
    if(num>70)
    {
        cout<<"baby "<<_name<<" is crying!"<<endl;
    }
    else
    {
        cout<<"baby "<<_name<<" is still sleeping!"<<endl;
    }
}

class Subject
{
public:
    virtual void attach(Observer*)=0;
    virtual void detach(Observer*)=0;
    virtual void notify()=0;
    virtual ~Subject(){ cout<<"~Subject()"<<endl; }
};


class Ring
:public Subject
{
public:
    virtual void attach(Observer*);
    virtual void detach(Observer*);
    virtual void notify();
    void isPressing();
private:
    list<Observer*> _oblist;
    bool _isAlarming=false;
};
void Ring::attach(Observer* p)
{
    auto it = std::find(_oblist.begin(),_oblist.end(),p);
    if(it==_oblist.end())
    {
        _oblist.push_front(p);
    }

}

void Ring::detach(Observer* p)
{
    auto it = std::find(_oblist.begin(),_oblist.end(),p);
    if(it!=_oblist.end())
    {
        _oblist.push_front(p);
    }
}
void Ring::isPressing()
{
    if(!_isAlarming)
    {
        _isAlarming=true;
        notify();
    }
    _isAlarming=false;
}
void Ring::notify()
{
    for(auto i:_oblist)
    {
        i->update();
    }
}

class Guest
{
public:
    Guest(const char* s)
    :_name(s)
    {

    }
    void knock(Ring& ring)
    {
        ring.isPressing();
    }
private:
        string _name;
};
int main()
{
    Ring ring;
    unique_ptr<Baby> up3(new Baby("xiaohong"));
    unique_ptr<Baby> up4(new Baby("xiaolan"));
    ring.attach(up3.get());
    ring.attach(up4.get());

    Guest guest("xiaoming");
    
    guest.knock(ring);
    return 0;
}