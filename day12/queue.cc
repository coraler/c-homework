#include<iostream>
using std::cout;
using std::endl;
template<typename T>
class queue
{
public:
    queue(int capicity=10)
    :_start(new T[capicity+1]())
    ,_begin(0)
    ,_end(0)
    ,_capicity(capicity)
    {
        
    }
    ~queue()
    {
        if(_start)
            delete[] _start;
    }
    void push(T work);
    void pop();
    T front()
    {
        if(!empty())
        {
            return _start[_begin];
        }
        cout<<"队列为空"<<endl;
        return _start[_begin];
    }
    T end()
    {
        if(!empty())
        {
            return _start[(_end+_capicity-1)%_capicity];
        }
        cout<<"队列为空"<<endl;
        return _start[_begin];
    }
    bool empty()
    {
        return _end==_begin;
    }
    bool full()
    {
        return (_end+1)%_capicity==_begin;
    }
private:
    T *_start;
    int _capicity,_begin,_end;;
};
template<class T>
void queue<T>::push(T work)
{
    if(!full())
    {
        _start[_end]=work;
        _end=(_end+1)%_capicity;
    }
    else
    {
        cout<<"队列满了，不好意思"<<endl;
    }
}

template<class T>
void queue<T>::pop()
{
    if(!empty())
    {
        _end=(_end+_capicity-1)%_capicity;
    }
    cout<<"队列为空"<<endl;
}

void test()
{
    queue<int> work(10);
    work.pop();
    work.push(12);
    work.push(13);
    work.push(12);
    work.push(12);
    cout<<work.front()<<endl;
    cout<<work.end()<<endl;
}

int main()
{
    test();
    return 0;
}