//
// Created by HBat on 2018/6/18.
//

#ifndef SHAPEPOINT_SQUARE_H
#define SHAPEPOINT_SQUARE_H

#include "Shape.h"
#include "Point.h"

class Square:public Shape
{
public:
    Square(Point = Point(0,0), double = 1.0);
    virtual void draw();
    virtual void reshape(Point);
    void setWidth(double);
private:
    Point v1;
    double width;

};

#endif //SHAPEPOINT_SQUARE_H
