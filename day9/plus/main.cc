#include"tinyxml2.h"

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<boost/regex.hpp>
using namespace std;
using namespace tinyxml2;
class information
{
    public:
        information()
        {

        }
        ~information()
        {

        }
    public:
        string title;
        string link;
        string description;
        string  content;
        string lagnguage;
        string copyright;
        string pubdate; 
        string guid;
        string dccreator;
};
void traverse(vector <information> * _vecotr){
    //string filename = "pagelib.dat";
    std::ofstream _ostream("pagelib.dat",std::ios::app);

    vector<information>::iterator _begin= _vecotr->begin();
    vector<information>::iterator _end= _vecotr->end();

    ++_begin;
    while(_begin!=_end)
    {
        _ostream<<"<doc>"<<endl;
        _ostream<<"<title>"<<_begin->title<<"</title>"<<endl;
        _ostream<<"<link>"<<_begin->link<<"</link>"<<endl;
        _ostream<<"<description>"<<_begin->description<<"</description>"<<endl;
        _ostream<<"<content>"<<_begin->content<<"</content>"<<endl;
        _ostream<<"</doc>"<<endl;
        ++_begin;
    }
}

void example()
{
    XMLDocument doc;
    doc.LoadFile("test.xml");
    const char* context= doc.FirstChildElement("Hello")->GetText();
    cout<<"Hello,"<<context<<endl;
}

int main()
{
    //example();
    vector<information> infoVec;
    XMLDocument doc;
    doc.LoadFile("coolshell.xml");
    cout<<doc.Error()<<endl;
    if(doc.Error()!=0)
    {
        cout<<"load file error"<<endl;
        return 0;
    }
    XMLElement* root=doc.RootElement();
    XMLElement* channel=root->FirstChildElement("channel");
    if(channel==NULL)
    {
        cout<<"error channel"<<endl;
        return 0;
    }
    boost::regex reg("(<.*?>)"); 
    XMLElement * title = channel->FirstChildElement("title");
    cout<<title->GetText()<<endl;
    cout<<title->Name()<<endl;
    XMLElement * link = title->NextSiblingElement("link");
    cout<<link->GetText()<<endl;
    cout<<link->Name()<<endl;
    XMLElement * description = link->NextSiblingElement("description");
    cout<<description->GetText()<<endl;
    cout<<description->Name()<<endl;
    XMLElement * item=description->NextSiblingElement("item");
    while(item)
    {
        information tmp;
        XMLElement* item_child=item->FirstChildElement();
        while(item_child)
        {
            cout << item_child->GetText() << endl;
            if (strcmp(item_child->Name(), "title") == 0)
            {
                tmp.title.clear();
                tmp.title.append(item_child->GetText());
                cout << "title-------------------------------------------" << endl;

            }else if(strcmp(item_child->Name(),"link")==0){
                tmp.link.clear();
                tmp.link.append(item_child->GetText());
                cout<<"link-------------------------------------------"<<endl;

            }else if(strcmp(item_child->Name(),"description")==0){
                tmp.description.clear();
                tmp.description.append(item_child->GetText());
                cout<<"description------------------------------------"<<endl;

            }else if(strncmp(item_child->Name(),"content",7)==0){
                tmp.content.clear();
                string work(item_child->GetText());
                work=boost::regex_replace(work,reg,"");
                tmp.content.append(work);
                cout<<"content------------------------------------"<<endl;

            }else if(strcmp(item_child->Name(),"dc:creator")==0){
                tmp.dccreator.clear();
                tmp.dccreator.append(item_child->GetText());
                cout<<"dccreator ------------------------------------"<<endl;

            }else if(strcmp(item_child->Name(),"pubdate")==0){
                tmp.pubdate.clear();
                tmp.pubdate.append(item_child->GetText());
                cout<<"pubdate ------------------------------------"<<endl;

            }else if(strcmp(item_child->Name(),"guid")==0){
                tmp.guid.clear();
                tmp.guid.append(item_child->GetText());
                cout<<"guid------------------------------------"<<endl;
            }
            item_child=item_child->NextSiblingElement();
        }
        infoVec.push_back(tmp);
        item=item->NextSiblingElement();
    }
    traverse(&infoVec);
    return 0;

}

