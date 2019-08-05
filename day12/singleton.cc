#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
template<class T>
class Singleton
{
public:
    template<typename...Args>
    static T* getinstance(Args...args)
    {
        if(!singletonWork)
        {
            singletonWork=new T(args...);
        }
        return singletonWork;
    }

    static void destroy()
    {
        if(singletonWork)
        {
            delete singletonWork;
        }
    }
private:
    static T* singletonWork;
};

template<class T>
T* Singleton<T>::singletonWork=NULL;

class Point
{
public:
    Point()=default;
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {

    }
    void print()
    {
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }
private:
    int _ix=0;
    int _iy=0;
};
class Computer
{
public:
    Computer(const char* name,const char* model,double price)
    :_name(name)
    ,_model(model)
    ,_price(price)
    {

    }
    void print()
    {
        cout<<_name<<endl;
        cout<<_model<<endl;
        cout<<_price<<endl;
    }
private:
    string _name;
    string _model;
    double _price;
    
};
void test()
{
    Computer* p1=Singleton<Computer>::getinstance("Xiongda","Mac",6666);

    Computer* p2=Singleton<Computer>::getinstance("Xionger","Mac",7777);
    p1->print();
    p2->print();
    Singleton<Computer>::destroy();

    Point *p3=Singleton<Point>::getinstance(1,2);
    Point *p4=Singleton<Point>::getinstance(3,4);
    p3->print();
    p4->print();

    Singleton<Point>::destroy();
}

int main()
{
    test();
    return 0;
}