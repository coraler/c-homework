#pragma once
#include<iostream>
using std::cout;;
using std::endl;
class Line
{
public:
    Line(int,int,int,int);
    ~Line();
    void print() const;
    class lineImp;
private:
    lineImp * _pimpl;
};