#include<iostream>
using std::cout;
using std::endl;
class stack
{
public:
    stack()
    :_top(-1)
    {

    }
    bool empty();//判断栈空
    bool full();//判断栈满
    void push(int);//入栈
    void pop();//出栈
    int top();//读出栈顶元素
    void print();//打印一遍栈内元素
private:
    int _work[10];
    int _top;
};
inline bool stack::empty()
{
    if(-1==_top)
        return 1;
    return 0;
}
inline bool stack::full()
{
    if(9==_top)
        return 1;
    return 0;
}
void stack::push(int x)
{
    if(!full())
    {
        _work[++_top]=x;
    }
    else
    {
        cout<<"栈满了，程序终止"<<endl;
    }
}
void stack::pop()
{
    if(!empty())
    {
        _top--;
    }
    else
    {
        cout<<"栈为空，不能出栈"<<endl;
    }
}
int stack::top()
{
    if(!empty())
    {
        return _work[_top];
    }
    else
    {
        cout<<"栈为空，没有栈顶元素"<<endl;
        return 0;
    }
}
void stack::print()
{
    if(!empty())
    {
        int i=_top;
        while(i!=-1)
        {
            cout<<_work[i--]<<endl;
        }
    }
    else
    {
        cout<<"栈为空"<<endl;
    }
}
int main()
{
    stack myStack;
    myStack.push(10);
    myStack.print();
    myStack.push(12);
    myStack.print();
    myStack.push(14);
    myStack.print();
    cout<<myStack.top()<<endl;
    myStack.pop();
    cout<<myStack.top()<<endl;
}