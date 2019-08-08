#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
class Solution
{
public:
    int leederLength(string beg,string end,vector<string>& work);
};

int Solution::leederLength(string beg,string end,vector<string>& work)
{
    auto it=std::find(work.begin(),work.end(),end);
    if(it==work.end())
    {
        return 0;
    }
    int depth=1;
    vector<vector<pair<string,int>>>  depthRecord;
    depthRecord.push_back(vector<pair<string,int>> {pair<string,int>(beg,0)});
    while(work.size())
    {
        vector<pair<string,int>>  record,lastRecord(depthRecord.back());
        for(auto i=lastRecord.begin();i!=lastRecord.end();++i)
        {
            for (auto j = work.begin(); j != work.end(); ++j)
            {
                int count=0;
                for(int k=0;k<i->first.size();++k)
                {
                    if(i->first[k]!=(*j)[k])
                    {
                        ++count;
                        if(count>1)
                        {
                            break;
                        }
                    }
                }
                if(count==1)
                {
                    record.push_back(pair<string,int>((*j),depth));
                }
            }
        }
        ++depth;
        for(auto i=record.begin();i!=record.end();++i)
        {
            if(i->first==end)
            {
                return depth;
            }
        }
        auto i=std::remove_if(work.begin(),work.end(),[record,depth](string s){auto it=std::find(record.begin(),record.end(),pair<string,int>(s,depth-1));return it!=record.end();});
        work.erase(i,work.end());
        depthRecord.push_back(record);
    }
}
void test()
{
    Solution p;
    vector<string> work{"hot","dot","dog","lot","log"};
    string beg("hit"),end("cog");
    cout<<p.leederLength(beg,end,work)<<endl;
}
int main()
{
    test();
    return 0;
}