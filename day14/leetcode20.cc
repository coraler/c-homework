#include<iostream>
#include<string>
#include<stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;
class BracketMatch
{
public:
    bool Matching(string s);
private:
    stack<char> _work;
};

bool BracketMatch::Matching(string s)
{
    while(!_work.empty())
        _work.pop();
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==')'||s[i]=='}'||s[i]==']')
        {
            if(_work.empty())
            {
                return false;
            }
            else
            {
                if(s[i]==')')
                {  
                    if(_work.top()!='(')
                    {
                        return false;
                    }
                    _work.pop();
                }
                else if(s[i]=='}')
                {
                    if(_work.top()!='{')
                    {
                        return false;
                    }
                    _work.pop();
                }
                else if(s[i]==']')
                {
                    if(_work.top()!='[')
                    {
                        return false;
                    }
                    _work.pop();
                }
            }
        }
        else
        {
            _work.push(s[i]);
        }
    }
    if(!_work.empty())
    {
        return false;
    }
    return true;
}
void test()
{
    string s;
    BracketMatch work;
    while(std::cin>>s)
    {
        if(work.Matching(s))
        {
            cout<<"true"<<endl;
        }
        else
        {
            cout<<"false"<<endl;
        }
        
    }

}

int main()
{
    test();
    return 0;
}