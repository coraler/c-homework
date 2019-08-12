#include<iostream>
#include<memory>
using std::cout;
using std::endl;
using std::unique_ptr;
class Figure
{
public:
     virtual void display() const=0;
     virtual ~Figure()
     {
         cout<<"~Figure()"<<endl;
     }
};
void display(Figure *fg)
{
    fg->display();
}
class Square
:public Figure
{
public:
    Square(int len)
    :_sideLen(len)
    {

    }
    void display() const
    {
        cout<<"这是个边长为"<<_sideLen<<"的正方形"<<endl;
    }
private:
    int _sideLen;
};
class Triangle
:public Figure
{
public:
    Triangle(int len)
    :_sideLen(len)
    {

    }
    void display() const
    {
        cout<<"这是个边长为"<<_sideLen<<"的正三角形"<<endl;
    }
private:
    int _sideLen;
};

class Factory
{
public:
    virtual Figure* create(int )=0;
    virtual ~Factory(){ cout<<"~Factory()"<<endl; }
};

class SquareFactory
:public Factory
{
public:
    virtual Figure* create(int len)
    {
        return new Square(len);
    }
};

class TriangleFactory
:public Factory
{
public:
    virtual Figure* create(int len)
    {
        return new Triangle(len);
    }
};


int main()
{
    SquareFactory work1;
    unique_ptr<Figure> up1(work1.create(2));
    display(up1.get());

    TriangleFactory work2;
    unique_ptr<Figure> up2(work2.create(3));
    display(up2.get());
    return 0;
}