#ifndef POINT_H
#define POINT_H

class Point
{
public:
       Point(double xaxis,double yaxis);
       double getX();
       double getY();
private:
       double _xaxis;
       double _yaxis;
};



Point::Point(double x,double y)
{
    _xaxis=x;
    _yaxis=y;
}

double Point::getX()
{
    return _xaxis;
}

double Point::getY()
{
    return _yaxis;
}


#endif // POINT_H
