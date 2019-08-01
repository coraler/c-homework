#include<iostream>
#define PI 3.14
using std::cout;
using std::endl;
class Circle
{
public:
    Circle()=default;
    Circle(double r)
    :_r(r)
    {

    }
    double getArea()//获得园的面积
    {
        return _r*_r*PI;
    }
    double getPerimeter()
    {
        return 2*_r*PI;
    }
    void show()
    {
        cout<<"圆的半径："<<_r<<endl;
        cout<<"圆的面积："<<getArea()<<endl;
        cout<<"圆的周长："<<getPerimeter()<<endl;
    }
private:
    double _r=0;
};
class Cylinder
:public Circle
{
public:
    Cylinder(double r,double h)
    :Circle(r)
    ,_h(h)
    {

    }
    double getVolume()
    {
        return _h*getArea();
    }
    void showVolume()
    {
        cout<<"圆柱体的高是："<<getVolume()<<endl;
    }
private:
    double _h;
};

void test()
{
    Cylinder work(2,1);
    work.showVolume();
}
int main()
{
    test();
    return 0;
}