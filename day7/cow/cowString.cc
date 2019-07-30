#include<string.h>

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
static char r=0;
class cowString
{
public:
cowString()
:_pstr(new char[1]())
{

}
cowString(const char* str)
:_pstr(new char[strlen(str)+5]+4)
{
    strcpy(_pstr,str);
    refCountInit();
}
cowString(cowString & s)
{
    _pstr=s._pstr;
    refCountIncrease();
}
cowString & operator=(cowString & s)
{
    _pstr=s._pstr;
    refCountIncrease();
    return *this;
}
~cowString()
{
    cout<<"this is 析构函数"<<endl;
    refCountDecrease();
}
int size()
{
    return strlen(_pstr)-4;
}
int refCount()
{
    return *(int*)(_pstr-4);
}
char& operator[](int x)//这里返回必须加引用，否则这里就会进行复制了
{
    if(x>=0&&x<this->size())
    {
        if(refCount()==1)
            return _pstr[x];
        else
        {
            char* tmp=new char[strlen(_pstr)+5];
            strcpy(tmp+4,_pstr);
            refCountDecrease();
            _pstr=tmp+4;
            refCountInit();
            return _pstr[x];
        }
    }
    else
    {
        return r;
    }
}
const char* c_str()
{
    return _pstr;
}
friend ostream &operator<<(ostream &os,cowString &p);
private:
void refCountInit()
{
    *(int*)(_pstr-4)=1;
}
void refCountIncrease()
{
    ++*(int*)(_pstr-4);
}
void refCountDecrease()
{
    if((--*(int*)(_pstr-4))==0)
    {
        delete[] (_pstr-4);
        _pstr=nullptr;
    }
}
char * _pstr;
};
ostream& operator<<(ostream &os,cowString &p)
{
    os<<p._pstr;
    return os;
}
int main()
{
    cowString s1("hello");
    cowString s2(s1);
    cowString s3=s1;
    cout<<"s1 的引用计数"<<s1.refCount()<<endl;
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
    cout<<"s3="<<s3<<endl;
    printf("s1的地址是%p\n",s1.c_str());
    printf("s2的地址是%p\n",s2.c_str());
    printf("s3的地址是%p\n",s3.c_str());
    cout<<"*****************************"<<endl;
    cout<<"s3[0]="<<s3[0]<<endl;
    cout<<"s1 的引用计数"<<s1.refCount()<<endl;
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
    cout<<"s3="<<s3<<endl;
    printf("s1的地址是%p\n",s1.c_str());
    printf("s2的地址是%p\n",s2.c_str());
    printf("s3的地址是%p\n",s3.c_str());
    cout<<"*****************************"<<endl;
    s3[0]='H';
    cout<<"s1 的引用计数"<<s1.refCount()<<endl;
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
    cout<<"s3="<<s3<<endl;
    printf("s1的地址是%p\n",s1.c_str());
    printf("s2的地址是%p\n",s2.c_str());
    printf("s3的地址是%p\n",s3.c_str());
    return 0;
}