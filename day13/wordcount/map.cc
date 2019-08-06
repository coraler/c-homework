#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include<utility>
using std::cout;
using std::endl;
using std::map;
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
    map<string,int>  work;
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
    while(std::getline(file,line))//这里io次数有点多，可以优化，每次读一行
    {
        ss<<line;
        //cout<<ss.str()<<endl;
        while(ss>>buf)
        {
            ++work[buf];
        }
        ss.clear();//重置流状态
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
    //用迭代器遍历map，返回的是pair的指针
    for(auto it=work.begin();it!=work.end();++it)
    {
        file<<it->first<<" "<<it->second<<endl;
    }
    file.close();
}
void Dictionary::print()
{
    for(auto it=work.begin();it!=work.end();++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
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


