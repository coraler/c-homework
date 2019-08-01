#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
class Person
{
public:
    Person(const char* name,int age)
    :_name(name)
    ,_age(age)
    {

    }
    void display()
    {
        cout<<"姓名："<<_name<<endl;
        cout<<"年龄："<<_age<<endl;
    }
private:
    string _name;
    int _age;
};
class Employee
:public Person
{
public:
    Employee(const char*name,int age,const char* department,int salary)
    :Person(name,age)
    ,_department(department)
    ,_salary(salary)
    {

    }
    void display()
    {
        Person::display();
        cout<<"部门："<<_department<<endl;
        cout<<"薪资："<<_salary<<endl;
    }
    int getSalary()
    {
        return _salary;
    }
private:
    string _department;
    int _salary;
};

void test()
{
    Employee worker1("xiongda",18,"工厂",1000);
    Employee worker2("xionger",19,"医院",1100);
    Employee worker3("xiongsan",20,"商店",1200);
    worker1.display();
    cout<<"******************"<<endl;
    worker2.display();
    cout<<"******************"<<endl;
    worker3.display();
    cout<<"******************"<<endl;
    double avg=(double)(worker1.getSalary()+worker2.getSalary()+worker3.getSalary())/3;
    cout<<"三人的平均薪资是："<<avg<<endl;
}

int main()
{
    test();
    return 0;
}