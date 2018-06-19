//
// Created by HBat on 2018/6/18.
//

#ifndef SHAPEPOINT_SHAPE_H
#define SHAPEPOINT_SHAPE_H

#include "Point.h"
#include <cstdio>

class Shape
{
public:
    virtual ~Shape(){}
    virtual void draw()=0;
    virtual void reshape(Point)=0;
};


#endif //SHAPEPOINT_SHAPE_H
