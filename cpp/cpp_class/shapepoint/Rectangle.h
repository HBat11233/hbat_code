//
// Created by HBat on 2018/6/18.
//

#ifndef SHAPEPOINT_RECTANGLE_H
#define SHAPEPOINT_RECTANGLE_H

#include "Shape.h"
#include "Point.h"

class Rectangle:public Shape
{
public:
    Rectangle(Point = Point(0,0),Point = Point(1,1), double = 1.0, double = 1.0);
    virtual void draw();
    virtual void reshape(Point);
    void setWidth(double);
    void setHidth(double);
private:
    Point a;
    Point b;
    double width;
    double height;
};
#endif //SHAPEPOINT_RECTANGLE_H
