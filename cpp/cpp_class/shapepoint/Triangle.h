//
// Created by HBat on 2018/6/18.
//

#ifndef SHAPEPOINT_TRIANGLE_H
#define SHAPEPOINT_TRIANGLE_H

#include "Shape.h"
#include "Point.h"

class Triangle :public Shape
{
public:
    Triangle(Point = Point(0,1),Point = Point(-0.87,-0.5),Point = Point(0.87,-0.5));
    virtual void draw();
    virtual void reshape(Point);
private:
    Point a;
    Point b;
    Point c;
};

#endif //SHAPEPOINT_TRIANGLE_H
