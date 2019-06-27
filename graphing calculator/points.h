#ifndef POINTS_H
#define POINTS_H


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

#endif // POINTS_H
