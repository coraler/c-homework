#include<iostream>
using std::cout;
using std::endl;
class theOne
{
public:
class autoFade
{
public:
autoFade()
{
    cout<<"this is autoFade()"<<endl;
}
~autoFade()
{
    delete pGet;
    cout<<"this is ~autoFade()"<<endl;
}
private:
};
static theOne* getinstance(int x)
{
    if(pGet==nullptr)
    {
        pGet=new theOne(x);
    }
    return pGet;
}
private:
theOne(int x)
:_one(x)
{
    
}
~theOne()
{
    
}
static theOne* pGet;
static autoFade autoF;
int _one;
};

theOne* theOne::pGet=nullptr;
theOne::autoFade theOne::autoF;
int main()
{
    theOne* work=theOne::getinstance(1);
    return 0;
}