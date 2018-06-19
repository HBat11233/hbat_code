//
// Created by HBat on 2018/6/18.
//

#ifndef SHAPEPOINT_USERAPP_H
#define SHAPEPOINT_USERAPP_H

#include "Graphics.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Point.h"

class UserApp
{
public:
    void init();
    void display();
    void reshape(int,int,Point);
private:
    std::vector<Graphics>que;
    Triangle tr;
    Square sq;
    Rectangle re;
};

#endif //SHAPEPOINT_USERAPP_H
