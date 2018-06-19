//
// Created by HBat on 2018/6/18.
//

#ifndef SHAPEPOINT_GRAPHICS_H
#define SHAPEPOINT_GRAPHICS_H

#include "Shape.h"
#include <vector>
#include <cstdio>

class Graphics
{
public:
    Graphics(Shape *);
    void draw();
    void add(Shape *);
    void clear();
    std::vector <Shape *> const & getQue();
private:
    std::vector <Shape *> que;

};

#endif //SHAPEPOINT_GRAPHICS_H
