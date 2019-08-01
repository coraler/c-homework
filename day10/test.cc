#include<iostream>
using std::cout;
using std::endl;
class test
{
public:
    test(int x)
    :_x(x)
    {

    }
    void print()
    {
        cout<<"_x="<<_x<<endl;
        cout<<"_y="<<_y<<endl;
    }
private:
    int _x=0;
    int _y=0;     
};
int main()
{
    test work(1);
    work.print();;
    return 0;
}