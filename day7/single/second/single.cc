#include<stdlib.h>

#include<iostream>
using std::cout;
using std::endl;
class theOne
{
public:
static theOne* getinstance(int x)
{
    if(pGet==nullptr)
    {
        atexit(destroy);
        pGet=new theOne(x);
    }
    return pGet;
}
private:
static void destroy()
{
    if(pGet)
        delete pGet;
}
theOne(int x)
:_one(x)
{
    
}
~theOne()
{
    
}
static theOne* pGet;
int _one;
};

theOne* theOne::pGet=nullptr;
int main()
{
    theOne* work=theOne::getinstance(1);
    return 0;
}