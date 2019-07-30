#include<iostream>
using std::cout;
using std::endl;
class empty{
public:
empty(){
    cout<<"this is empty"<<endl;
}
~empty(){
    cout<<"this is ~empty()"<<endl;
}
private:
void* operator new(std::size_t sz);
void operator delete(void* p);
};