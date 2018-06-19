//
// Created by HBat on 2018/6/18.
//

#include "Graphics.h"

Graphics::Graphics(Shape *a)
{
    add(a);
}

void Graphics::clear()
{
    que.clear();
    return;
}

void Graphics::draw()
{
    for(Shape * p:que)
    {
        p->draw();
        printf("\n");
    }
}

void  Graphics::add(Shape *a)
{
    que.push_back(a);
    return;
}

std::vector <Shape *> const & Graphics::getQue()
{
    return que;
}