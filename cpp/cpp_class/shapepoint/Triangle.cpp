//
// Created by HBat on 2018/6/18.
//

#include "Triangle.h"

Triangle::Triangle(Point a, Point b, Point c)
:a(a),b(b),c(c)
{}

void Triangle::draw()
{
    printf("This is Triangle!\n");
    printf("a = ");
    a.print();
    printf("\n");
    printf("b = ");
    b.print();
    printf("\n");
    printf("c = ");
    c.print();
    printf("\n");
    return;
}

void Triangle::reshape(Point offset)
{
    printf("old Triangle:\n");
    draw();
    a=offset+Point(0,1);
    b=offset+Point(-0.87,-0.5);
    c=offset+Point(0.87,-0.5);
    printf("new Triangle:\n");
    draw();
    return;
}