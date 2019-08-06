#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<set>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;


class ManageTXT
{
public:
    void init(const char* fileName);//输入文件名进行各种查找前的初始化工作，可以重用
    void query(const char* word);//查找单词的函数，打印信息
private:
    vector<string> _content;
    map<string,set<int>> _wordLine;
    map<string,int> _wordCount;
};

void ManageTXT::init(const char* fileName)
{
    _content.clear();
    _wordLine.clear();
    _wordCount.clear();
    std::fstream fs;
    fs.open(fileName);
    string buf1, buf2;
    std::stringstream ss;
    int i = 0;
    while (std::getline(fs, buf1))
    {
        _content.push_back(buf1);
        i++;
        ss << buf1;
        while (ss >> buf2)
        {
            _wordLine[buf2].insert(i);
            ++_wordCount[buf2];
        }
        ss.clear();
    }
}

void ManageTXT::query(const char* word)
{
    cout<<word<<" "<<"occurs "<<_wordCount[word]<<" times."<<endl;
    for(auto it=_wordLine[word].begin();it!=_wordLine[word].end();++it)
    {
        cout<<"          "
            <<"(line "<<*it<<") "<<_content[*it-1]<<endl;
    }
}
//下面是测试程序
int main(int argc,char* argv[])
{
    if(argc!=3)//为了方便这里运行时给连两个参数，第一个是文件名，另一个是要查的单词
                //以后有时间再改为可以互动式的
    {
        cout<<"error argc"<<endl;
        return 0;
    }
    ManageTXT work;
    work.init(argv[1]);
    work.query(argv[2]);
    return 0;
}