//
// Created by HBat on 2018/6/18.
//

#include "Rectangle.h"

Rectangle::Rectangle(Point a, Point b, double width, double height)
:a(a),b(b),width(width),height(height)
{}

void Rectangle::draw()
{
    printf("This is Rectangle!\n");
    printf("a = ");
    a.print();
    printf("\n");
    printf("b = ");
    b.print();
    printf("\n");
    printf("width = %lf\n",width);
    printf("height = %lf\n",height);
    return;
}

void Rectangle::reshape(Point offset)
{
    printf("old Rectangle:\n");
    draw();
    a=offset+Point(-width/2,height/2);
    b=offset+Point(width/2,-height/2);
    printf("new Rectangle:\n");
    draw();
}