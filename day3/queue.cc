#include<iostream>
using std::cout;
using std::endl;
class queue//循环队列
{
private:
    int _work[10];
    int _front,_rear;
public:
    queue()
    :_front(0),_rear(0)
    {

    }
    bool empty();//判断队列空
    bool full();//判断队列满
    void push(int);//队列栈
    void pop();//出队列
    int front();//读出队列头元素
    int rear();//读出队列尾元素
    void print();//打印一遍栈内元素
};
inline bool queue::empty()
{
    if(_front==_rear)
        return 1;
    return 0;
}
inline bool queue::full()
{
    if((_rear+1)%10==_front)
        return 1;
    return 0;
}
void queue::push(int x)
{
    if(!full())
    {
        _work[_rear]=x;
        ++_rear;
        _rear=_rear%10;
    }
    else
    {
        cout<<"队列满了"<<endl;
    }
}
void queue::pop()
{
    if(!empty())
    {
        ++_front;
        _front=_front%10;
    }
    else
    {
        cout<<"队列为空"<<endl;
    }
}
int queue::rear()
{
    if(!empty())
    {
        if(_rear==0)
        {
            return _work[9];
        }
        return _work[_rear-1];
    }
    else
    {
        cout<<"队列为空"<<endl;
        return 0;
    }
}
int queue::front()
{
    if(!empty())
    {
        return _work[_front];
    }
    else
    {
        cout<<"队列为空"<<endl;
        return 0;
    }
}
void queue::print()
{
    if(!empty())
    {
        int i=_front;
        while(i!=_rear)
        {
            cout<<_work[i++]<<endl;
        }
    }
    else
    {
        cout<<"队列为空"<<endl;
    }
}
int main()
{
    queue myQueue;
    myQueue.push(1);
    myQueue.print();
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.print();
    myQueue.pop();
    cout<<myQueue.front()<<"  "<<myQueue.rear()<<endl;
    return 0;
}