#include"line.h"
class Line::lineImp
{
private:
    class Point
    {
    public:
        Point(int x,int y)
        :_ix(x),
        _iy(y)
        {}
        void ptintPoint()
        {
            cout<<"("<<_ix<<","<<_iy<<")";
        }
    private:
        int _ix;
        int _iy;
    };
public:
    lineImp(int x1,int x2,int y1,int y2)
    :_pt1(x1,y1)
    ,_pt2(x2,y2)
    {

    }
    void printLine()
    {
        _pt1.ptintPoint();
        cout<<"---->";
        _pt2.ptintPoint();
        cout<<endl;
    }
private:
    Point _pt1,_pt2;
};
Line::Line(int x1,int x2,int y1,int y2)
:_pimpl(new lineImp(x1,x2,y1,y2))
{
    
}
Line::~Line()
{
    delete _pimpl;
}

void Line::print() const
{
    _pimpl->printLine();
}