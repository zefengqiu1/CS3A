#include "points.h"

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
