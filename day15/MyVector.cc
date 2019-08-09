#include<iostream>
#include<memory>
using namespace std;
template<class T>
class MyVector
{
public:
    MyVector()
    :_start(nullptr)
    ,_end(nullptr)
    ,_end_of_storage(nullptr)
    {

    }
    ~MyVector()
    {
        if(_start)
        {
            for(auto i=_start;i!=_end;++i)
            {
                _alloc.destroy(i);
            }
            _alloc.deallocate(_start,capicity());
        }
    }

    void push_back(const T&);
    void pop_back();
    void display()
    {
        for(auto i=_start;i!=_end;++i)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
        cout<<"capicity="<<capicity()<<endl;
        cout<<"size="<<size()<<endl;
    }
    int size(){ return _end-_start; }
    int capicity(){ return _end_of_storage-_start; }
private:
    static allocator<T>  _alloc;
    T* _start;
    T* _end;
    T* _end_of_storage;   
};

template<class T>
allocator<T>  MyVector<T>::_alloc;

template<class T>
void MyVector<T>::push_back(const T& t)
{
    if(size()==capicity())
    {
        size_t newCapicity=capicity()*2>0?capicity()*2:1,record=size();
        auto work=_alloc.allocate(newCapicity);
        uninitialized_copy(_start,_end,work);
        for (auto i = _start; i != _end; ++i)
        {
            _alloc.destroy(i);
        }
        _alloc.deallocate(_start,capicity());
        _start=work;
        _end=work+record;
        _end_of_storage=_start+newCapicity;
    }
        _alloc.construct(_end++,t);
    
}
template<class T>
void MyVector<T>::pop_back()
{
    if(_start!=_end)
    {
        --_end;
    }
    else
    {
        cout<<"容器中没有内容"<<endl;
    }
}

void test()
{
    MyVector<int> vec;
    vec.push_back(1);
    vec.display();
    vec.push_back(1);
    vec.display();
    vec.push_back(1);
    vec.display();
    vec.push_back(1);
    vec.display();
    vec.push_back(1);
    vec.display();
}

int main()
{
    test();
    return 0;
}