#include<iostream>
#include<functional>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
template<class T,typename Compare=std::less<T>>//给默认值
class HeapSort//小顶堆
{
public:
    HeapSort(T* begin,T* end)//构造函数要求给一对指针
    {
        _work.clear();
        while(begin!=end)
        {
            _work.push_back(*begin);
            ++begin;
        }
    }
    void heapAdjust(int dad,int size);
    void sort();
    void display()
    {
        for(auto it=_work.begin();it!=_work.end();++it)//需要T类型有<<操作
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
private:
    vector<T> _work;
};
#define SWAP(a,b,c) {c=a; a=b; b=c;}
template<class T,typename Compare>
void HeapSort<T,Compare>::heapAdjust(int dad,int size)
{
    Compare compare;
    int son=dad*2+1;
    while(son<size)
    {
        if(son+1<size&&compare(_work[son+1],_work[son]))
        {
            ++son;
        }
        if(!compare(_work[dad],_work[son]))
        {
            T temp;
            SWAP(_work[dad],_work[son],temp);
            dad=son;
            son=dad*2+1;
        }
        else
        {
            break;
        }
    }
}

template<class T,typename Compare>
void HeapSort<T,Compare>::sort()
{
    for(int i=_work.size()/2-1;i>=0;--i)
    {
        heapAdjust(i,_work.size());
    }
    for(int i=_work.size()-1;i>0;--i)
    {
        T temp;
        SWAP(_work[0],_work[i],temp);
        heapAdjust(0,i);
    }
}

void test()
{
    int arr[]={5,8,9,6,7,56,8,2,4,6};
    HeapSort<int> work(arr,arr+10);
    work.sort();
    work.display();
}
template<class T>
struct Cmp
{
    bool operator()(const T& lhs,const T& rhs) const 
    {
        return lhs>rhs;
    }
};
void test2()
{
    int arr[]={5,8,9,6,7,56,8,2,4,6};
    HeapSort<int,Cmp<int>> work(arr,arr+10);
    work.sort();
    work.display();
}
int main()
{
    test2();
    test();
    return 0;
}