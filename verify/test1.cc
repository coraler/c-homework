#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
    /*virtual*/ void show()
    {
        cout<<"Base::show"<<endl;
    }
        
};

class Inherit
{
public:
    virtual void show()
    {
        cout<<"Inherit::show"<<endl;
    }
};

int main()
{
    Inherit work;
    Base* p=(Base*)&work;
    p->show();
    return 0; 
}

