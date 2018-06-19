//
// Created by HBat on 2018/6/18.
//

#ifndef SHAPEPOINT_POINT_H
#define SHAPEPOINT_POINT_H

#include <cstdio>

class Point
{
public:
    Point(double x = 0,double y = 0):x(x),y(y){}
    void print(){printf("(%d,%d)",x,y);}
    Point const &operator + (const Point &a)
    {
        x+=a.x;
        y+=a.y;
        return *this;
    }
    double x;
    double y;
};

#endif //SHAPEPOINT_POINT_H
