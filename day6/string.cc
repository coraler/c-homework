#include<stdlib.h>
#include<string.h>

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
static char x=0;
class String {
    public:
        String()
        :_pstr(new char[1]())
        {}
        String(const char * str)
        :_pstr(new char[strlen(str)+1]())
        {
            strcpy(_pstr,str);
        }
        String(const String& rhs)
        :_pstr(new char[strlen(rhs._pstr)+1])
        {
            strcpy(_pstr,rhs._pstr);
        }
        ~String()
        {
            cout<<"this is ~String()"<<endl;
            if(_pstr)
                delete[] _pstr;
        }
        String &operator=(const String & rhs)
        {
            if(_pstr)
                delete[] _pstr;;
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
            return *this;
        }
        String &operator=(const char * str)
        {
            if(_pstr)
                delete[] _pstr;;
            _pstr=new char[strlen(str)+1]();
            strcpy(_pstr,str);
            return *this;
        }

        String &operator+=(const String &rhs)
        {
            int len=strlen(_pstr)+strlen(rhs._pstr);
            char* temp=new char[len+1]();
            sprintf(temp,"%s%s",_pstr,rhs._pstr);
            if(_pstr)
                delete[] _pstr;
            _pstr=temp;
            return *this;
        }
        String &operator+=(const char * str)
        {
            /* int len=strlen(this->_pstr)+strlen(str);
            char temp[len+1]={0};
            sprintf(temp,"%s%s",this->_pstr,str);
            if(this->_pstr)
                delete[] this->_pstr;
            this->_pstr=new char[len+1]();
            strcpy(this->_pstr,temp);
            return *this;*/
            int len=strlen(this->_pstr)+strlen(str);
            char* temp=new char[len+1]();
            sprintf(temp,"%s%s",this->_pstr,str);
            if(this->_pstr)
                delete[] this->_pstr;
            this->_pstr=temp;
            return *this;

        }

        char &operator[](std::size_t index)
        {
            if(index<0||index>strlen(_pstr)-1)
            {
                return x;
            }
            else
            {
                return _pstr[index];
            }
            
        }
        const char &operator[](std::size_t index) const//const成员函数只能被const成员调用
        {
            if(index<0||index>strlen(_pstr)-1)
            {

                return x;
            }
            else
            {
                return _pstr[index];
            }
        }

        std::size_t size() const
        {
            return strlen(_pstr);
        }
        const char* c_str() const
        {
            return _pstr;
        }

        friend bool operator==(const String &, const String &);
        friend bool operator!=(const String &, const String &);

        friend bool operator<(const String &, const String &);
        friend bool operator>(const String &, const String &);
        friend bool operator<=(const String &, const String &);
        friend bool operator>=(const String &, const String &);

        friend std::ostream &operator<<(std::ostream &os, const String &s);
        friend std::istream &operator>>(std::istream &is, String &s);

    private:
        char * _pstr;

};
bool operator==(const String & s1, const String & s2)
{
    if(strcmp(s1._pstr,s2._pstr)==0)
        return true;
    return false;
}
bool operator!=(const String & s1, const String & s2)
{
    return !(s1==s2);
}
bool operator<(const String &s1, const String &s2)
{
    if(strcmp(s1._pstr,s2._pstr)<0)
        return true;
    return false;
}
bool operator>(const String &s1, const String &s2)
{
    if(strcmp(s1._pstr,s2._pstr)>0)
        return true;
    return false;
}
bool operator<=(const String &s1, const String &s2)
{
    if(strcmp(s1._pstr,s2._pstr)<=0)
        return true;
    return false;
}
bool operator>=(const String &s1, const String &s2)
{
    if(strcmp(s1._pstr,s2._pstr)>=0)
        return true;
    return false; 
}
std::ostream &operator<<(std::ostream &os, const String &s)
{
    for(int i=0;i<s.size();++i)
    {
        os<<s[i];
    }
    return os;
}
std::istream &operator>>(std::istream &is, String &s)
{
    char x[2]={0};
    //if(strlen(s._pstr)!=0)
        //delete[] s._pstr;
    bzero(s._pstr,strlen(s._pstr));
    cout<<"this is operator>>()"<<endl;
    while(is>>x[0],x[0]!='*'&&!is.eof())
    {
        //cout<<x<<endl;
        s+=x;
        //cout<<s<<endl;
    }
    return is;
}
String operator+(const String &s1, const String &s2)
{
    char* tmp=new char[strlen(s1.c_str())+strlen(s2.c_str())+1];
    sprintf(tmp,"%s%s",s1.c_str(),s2.c_str());
    String s(tmp);
    return s;
}
String operator+(const String &s1, const char *c_s)
{
    char* tmp=new char[strlen(s1.c_str())+strlen(c_s)+1];
    sprintf(tmp,"%s%s",s1.c_str(),c_s);
    String s(tmp);
    return s;
}
String operator+(const char *c_s, const String &s1)
{
    char* tmp=new char[strlen(s1.c_str())+strlen(c_s)+1];
    sprintf(tmp,"%s%s",s1.c_str(),c_s);
    String s(tmp);
    return s;
}
int main()
{
#if 0
    char x[2]={0};
    cin>>x[0];
    cout<<x<<endl;
#endif 
#if 1
    String s1("i am s1"),s2("i am s2");
    //String s1,s2;
    char c_str[]="hello";
    cin>>s1>>s2;
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
    cout<<"s1+=s1 "<<(s1+=s1)<<endl;
    cout<<"s1+s2 "<<(s1+s2)<<endl;
    cout<<"c_str+s1 "<<c_str+s1<<endl;
    cout<<"s1+c_str "<<s1+c_str<<endl;
    cout<<"s1==s2 "<<(s1==s2)<<endl;
    cout<<"s1[0]  s2[1]"<<s1[0]<<"  "<<s2[2]<<endl;
    cout<<"s1>=s2 "<<(s1>=s2)<<endl;
    return 0;
#endif 
}
