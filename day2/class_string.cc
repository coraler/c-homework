#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
class String
{
    public:
        String()
        //:_pstr(NULL)不能给cout  char*的空指针，否则程序会崩溃
        :_pstr(new char[1])
        {
            _pstr=new char[1];
            _pstr[0]=0;
            cout<<"String()"<<endl;
        }
        String(const char *pstr)
        :_pstr(new char[strlen(pstr)+1])
        {
            strcpy(_pstr,pstr);
            cout<<"String(const char *pstr)"<<endl;
        }
        String(const String & rhs)//拷贝构造函数
        :_pstr(new char[strlen(rhs._pstr)+1])
        {
            strcpy(_pstr,rhs._pstr);
            cout<<"String(const String & rhs)"<<endl;
        }
        String & operator=(const String & rhs)//赋值函数
        {
            if(rhs._pstr==this->_pstr)
                return *this;
            delete []this->_pstr;
            this->_pstr=new char[strlen(rhs._pstr)+1];
            if(_pstr!=NULL)
                strcpy(_pstr,rhs._pstr);
            cout<<"String & operator=(const String & rhs)"<<endl;
            return *this;
        }
        ~String()
        {
            delete[] _pstr;
            cout<<"~String()"<<endl;
        }

        void print()
        {
            cout<<_pstr<<endl;
            _pstr=NULL;
            cout<<"print()"<<endl;
        }

    private:
        char * _pstr;

};
int main(void)
{
    String str1;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();       
    str3.print();   

    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    return 0;

}

