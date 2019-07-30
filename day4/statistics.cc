#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<utility>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::fstream;
using std::stringstream;
class Dictionary{
public:
void read(const string & filename);//读取文件内容写入词典中
void store(const string & filename);//将词典内容保存在指定文件中
void print();//打印字典中内容，用来观察效果
private:
vector<pair<string,int>> vec;
};
void Dictionary::read(const string & filename)
{
    fstream file(filename);
    if(!file)
    {
        cout<<"bad filename"<<endl;
        return;
    }
    string buf,line;
    stringstream ss;
    int flag=0;
    while(std::getline(file,line))//这里io次数有点多，可以优化，每次读一行
    {
        ss<<line;
        //cout<<ss.str()<<endl;
        while(ss>>buf)
        {
            //cout<<buf<<endl;
            for (pair<string, int> &search : vec)
            {
                if (search.first == buf)
                {
                    flag = 1;
                    search.second++;
                    break;
                }
            }
            if (flag == 0)
            {
                if (buf[0] < '0' || buf[0] > '9')
                {
                    pair<string, int> addNew(buf, 1);
                    vec.push_back(addNew);
                }
            }
            flag = 0;
        }
        ss.clear();
    }
    file.close();
}
void Dictionary::store(const string & filename)//会清空文件写的版本
{
    fstream file(filename);
    if(!file)
    {
        cout<<"bad filename"<<endl;
        return;
    }
    for(pair<string,int> &search:vec)
    {
        file<<search.first<<" "<<search.second<<endl;
    }
    file.close();
}
void Dictionary::print()
{
    for(pair<string,int> &search:vec)
    {
        cout<<search.first<<" "<<search.second<<endl;
    }
}

int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        cout<<"args error"<<endl;
        return 0;
    }
    string filename(argv[1]);
    Dictionary work;
    work.read(filename);
    work.print();
    work.store("record.txt");
}


