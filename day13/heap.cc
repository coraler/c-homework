#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
template<class T,typename Compare=std::less<T>>//给默认值
class HeapSort
{
public:
    HeapSort(T* begin,T* end)
    {
        while(begin!=end)
        {
            _work.push_back(*begin);
            ++begin;
        }
    }
    void heapAdjust();
    void sort();
private:
    vector<T> _work;
};

template<class T,typename Compare>
void HeapSort<T,Compare>::heapAdjust()
{
    
}