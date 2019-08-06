#include<iostream>
#include<vector>
#include<utility>
using std::cout;
using std::endl;
using std::vector;
using std::pair;
class LRUcache
{
public:
    LRUcache(int size)
    :_size(size)
    {}
    int get(int key);
    void put(int key,int value);
private: 
    int _size;
    vector<pair<int,int>> _work; 
};

int LRUcache::get(int key)
{
    for(auto it=_work.begin();it!=_work.end();++it)
    {
        if(it->first==key)
        {
            pair<int,int> p(it->first,it->second);
            _work.erase(it);
            _work.push_back(p);
            return p.second;
        }
    }
    return -1;
    
}

void LRUcache::put(int key,int value)//题目说了插入的值不会出现关键字相同的情况
{
     pair<int,int> p(key,value);
     if(_work.size()<_size)
     {
         _work.push_back(p);
     }
     else
     {
         auto it=_work.begin();
         _work.erase(it);
         _work.push_back(p);
     }
     
}
void test()//测试用例
{
    LRUcache cache(2);
    cache.put(1,1);
    cout<<"get(1)="<<cache.get(1)<<endl;
    cache.put(3,3);
    cout<<"get(2)="<<cache.get(2)<<endl;
    cache.put(4,4);
    cout<<"get(1)="<<cache.get(1)<<endl;
    cout<<"get(3)="<<cache.get(3)<<endl;
    cout<<"get(4)="<<cache.get(4)<<endl;
    cache.get(3);
    cache.put(5,5);
    cout<<"get(4)="<<cache.get(4)<<endl;
    cout<<"get(5)="<<cache.get(5)<<endl;
}

int main()
{
    test();
    return 0;
}