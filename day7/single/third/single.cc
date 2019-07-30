#include<pthread.h>
#include<stdlib.h>

#include<iostream>
using std::cout;
using std::endl;
class theOne
{
public:
static theOne* getinstance(int x)
{
    pthread_once(&once_control,func);
    pGet->_one=x;
    return pGet;
}
private:
static void func()
{
    if(pGet==nullptr)
    {
        atexit(destroy);
        pGet=new theOne();
    }
}
static void destroy()
{
    if(pGet)
        delete pGet;
}
theOne(int x=0)
:_one(x)
{
    
}
~theOne()
{
    
}
static theOne* pGet;
static pthread_once_t once_control;
int _one;
};

theOne* theOne::pGet=nullptr;
pthread_once_t theOne::once_control=PTHREAD_ONCE_INIT;
int main()
{
    theOne* work=theOne::getinstance(1);
    return 0;
}