#include<iostream>
class empty
{
    public:
    static empty* getempty()
    {
        if(!pInstance)
        {
            pInstance=new empty();
        }
        return  pInstance;
    }
    private:
    static empty* pInstance;
    empty()
    {

    }//构造函数需要放在私有成员
};
empty* empty::pInstance=nullptr;