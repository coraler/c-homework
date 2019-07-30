#include<iostream>
using std::cout;
using std::endl;
class empty{
public:
empty(){
    cout<<"this is empty()"<<endl;
}
void destroy(){
    delete this;//外面直接调用delete是不能通过编译的
                //就像的new会调用对象的构造函数一样
                //delete会调用对象的析构函数，这里
                //析构函数被私有化了所以只能自己写一个方法
}

private:
~empty(){
    cout<<"this is ~empty()"<<endl;
}
};