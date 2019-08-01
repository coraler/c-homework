#include<stdio.h>

#include<iostream>
#include<string>
#define sword 0
#define bomb  1
#define arrow 2
//标记武器号
#define dragon 1
#define ninja  2
#define iceman 3
#define lion   4
#define wolf   5
//标记武士编号


//全局数组
const char* equipmentName[3]={"sword","bomb","arrow"};


using std::cout;
using std::cin;
using std::endl;
using std::string;
class Warrior
{
public:
    Warrior(int hp)
    :_hp(hp)
    {

    }
    Warrior(int hp,int weapon1)
    :_hp(hp)
    {
        _equipment[weapon1]=1;
    }
    Warrior(int hp,int weapon1,int weapon2)
    :_hp(hp)
    {
        _equipment[weapon1]=1;
        _equipment[weapon2]=1;
    }
    const int* getEquipment()
    {
        return _equipment;
    }
private:
    int _equipment[3]={0};
    int _hp;
};

class Dragon
:public Warrior
{
public:
    Dragon(int hp,int weapon,double morale)
    :Warrior(hp,weapon)
    ,_morale(morale)
    {

    }
    void display()
    {
        const int *work=getEquipment();
        for(int i=0;i<3;++i)
        {
            if(work[i]==1)
            {
                printf("It has a %s,and it's morale is %5.2lf\n",equipmentName[i],_morale);
                break;
            }
        }
    }
private:
    double _morale;//士气
};
class Ninja
:public Warrior
{
public:
    Ninja(int hp,int weapon1,int weapon2)
    :Warrior(hp,weapon1,weapon2)
    {

    }
    void display()
    {
        const int *work=getEquipment();
        int weapon1,weapon2;
        for(int i=0;i<3;++i)
        {
            if(work[i]==1)
            {
                 weapon1=i;
                 for(int j=i+1;j<3;++j)
                 {
                     if(work[j]==1)
                     {
                         weapon2=j;
                         printf("It has a %s and %s\n",equipmentName[weapon1],equipmentName[weapon2]);
                         break;
                     }
                 }
            }
            break;
        }
    }

};
class Iceman
:public Warrior
{
public:
    Iceman(int hp,int weapon)
    :Warrior(hp,weapon)
    {

    }
    void display()
    {
        const int *work=getEquipment();
        for(int i=0;i<3;++i)
        {
            if(work[i]==1)
            {
                printf("It has a %s\n",equipmentName[i]);
                break;
            }
        }
    }
};
class Lion
:public Warrior
{
public:
    Lion(int hp,int lotalty)
    :Warrior(hp)
    ,_lotalty(lotalty)
    {

    }
    void display()
    {
        cout<<"It's lotalty is "<<_lotalty<<endl;
    }
private:
    int _lotalty;
};
class Wolf
:public Warrior
{
public:
    Wolf(int hp)
    :Warrior(hp)
    {

    }
};
class Headquarters
{
public:
    Headquarters(const char* name,int strength)
    :_Name(name)
    ,_strength(strength)
    {

    }
    int createWarrior(int warriorNum,int time);//制造武士的函数，返回值0代表制造成功，-1代表制造失败
private:
    int _countDragon=0;
    int _coumtNinja=0;
    int _countIceman=0;
    int _countLion=0;
    int _countWolf=0;
    int _numID=0;
    string _Name;
    int _strength;//当前还有的血量，创建时会给它初值
};
//全局变量所有武士的血量,好像可以用单例模式代替，以后再看看
int DragonHp;
int NinjaHp;
int IcemanHp;
int LionHp;
int WolfHp;

int Headquarters::createWarrior(int warriorNum,int time)
{
    if(warriorNum==dragon)//造龙骑士
    {
        if(DragonHp>_strength)
        {
            return -1;
        }
        else
        {
            int n=++_numID;
            _strength-=DragonHp;
            ++_countDragon;
            Dragon work(DragonHp,n%3,(double)_strength/DragonHp);
            printf("%03d",time);
            cout<<" "<<_Name<<" "<<"dragon"<<" "<<_numID
                <<" born with strength "<<DragonHp<<","<<_countDragon
                <<" dragon in "<<_Name<<" headquarter"<<endl;
            work.display();
            return 0;
        }
    }
    else if(warriorNum==ninja)//造忍者
    {
        if(NinjaHp>_strength)
        {
            return -1;
        }
        else
        {
            int n=++_numID;
            _strength-=NinjaHp;
            ++_coumtNinja;
            Ninja work(NinjaHp,n%3,(n+1)%3);
            printf("%03d",time);
            cout<<" "<<_Name<<" "<<"ninja"<<" "<<_numID
                <<" born with strength "<<NinjaHp<<","<<_coumtNinja
                <<" ninja in "<<_Name<<" headquarter"<<endl;
            work.display();
            return 0;
        }
    }
    else if(warriorNum==iceman)//造冰男
    {
        if(IcemanHp>_strength)
        {
            return -1;
        }
        else
        {
            int n=++_numID;
            _strength-=IcemanHp;
            ++_countIceman;
            Iceman work(IcemanHp,n%3);
            printf("%03d",time);
            cout<<" "<<_Name<<" "<<"iceman"<<" "<<_numID
                <<" born with strength "<<IcemanHp<<","<<_countIceman
                <<" iceman in "<<_Name<<" headquarter"<<endl;
            work.display();
            return 0;
        }
    }
    else if(warriorNum==lion)//造狮子
    {
        if(LionHp>_strength)
        {
            return -1;
        }
        int n=++_numID;
        _strength-=LionHp;
        ++_countLion;
        Lion work(LionHp,_strength);
        printf("%03d",time);
        cout<<" "<<_Name<<" "<<"lion"<<" "<<_numID
            <<" born with strength "<<LionHp<<","<<_countLion
            <<" lion in "<<_Name<<" headquarter"<<endl;
        work.display();
        return 0;
    }
    else if(warriorNum==wolf)//造狼
    {
        if(WolfHp>_strength)
        {
            return -1;
        }
        int n=++_numID;;
        _strength-=WolfHp;
        ++_countWolf;
        Wolf work(WolfHp);
        printf("%03d",time);
        cout<<" "<<_Name<<" "<<"wolf"<<" "<<_numID
            <<" born with strength "<<WolfHp<<","<<_countWolf
            <<" wolf in "<<_Name<<" headquarter"<<endl;
        return 0;
    }
}
//全局数组，表示红蓝队造武士的顺序
int redSequence[]={3,4,5,2,1};
int blueSequence[]={4,1,2,3,5};
void test()
{
    Headquarters work("red",20);
    work.createWarrior(3,1);
}
int main()
{
    //test();
    int strength,round;
    cin>>round;
    for(int i=0;i<round;++i)
    {
        int time=0,redFlag=0,blueFlag=0;
        cin>>strength>>DragonHp>>NinjaHp>>IcemanHp>>LionHp>>WolfHp;
        cout<<"case: "<<i+1<<endl;
        Headquarters red("red",strength);
        Headquarters blue("blue",strength);
        int redCur=0,blueCur=0;
        while(!redFlag||!blueFlag)
        {
            if(!redFlag)//红队造武士
            {
                int ret,record=redCur;
                do
                {
                    ret=red.createWarrior(redSequence[redCur],time);
                    ++redCur;
                    redCur%=5;
                    if(ret==-1&&redCur==record)
                    {
                        redFlag=1;
                        cout<<"00"<<time<<" red headquarter stop making warrior"<<endl;
                        break;
                    }
                } while (ret==-1);
            }
            if(!blueFlag)
            {
                int ret,record=blueCur;
                do
                {
                    ret=blue.createWarrior(blueSequence[blueCur],time);
                    ++blueCur;
                    blueCur%=5;
                    if(ret==-1&&blueCur==record)
                    {
                        blueFlag=1;
                        cout<<"00"<<time<<" blue headquarter stop making warrior"<<endl;
                        break;
                    }
                } while (ret==-1);
            }
            ++time;
        }
    }
    return 0;
}