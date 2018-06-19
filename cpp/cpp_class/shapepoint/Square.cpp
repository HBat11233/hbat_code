//
// Created by HBat on 2018/6/18.
//

#include "Square.h"

Square::Square(Point v1, double width)
:v1(v1),width(width)
{}

void Square::draw()
{
    printf("This is Square!\n");
    printf("v1 = ");
    v1.print();
    printf("\n");
    printf("width = %lf\n",width);
    return;
}

void Square::setWidth(double a)
{
    width=a;
    return;
}

void Square::reshape(Point offset)
{
    printf("old Square:\n");
    draw();
    v1=offset;
    printf("new Square:\n");
    draw();
    return;
}
