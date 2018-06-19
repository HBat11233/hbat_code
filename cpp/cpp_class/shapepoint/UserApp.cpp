//
// Created by HBat on 2018/6/18.
//
#include "UserApp.h"

void UserApp::init()
{
    que.push_back(Graphics(&tr));
    que[0].add(&sq);
    que[0].add(&re);
    return;
}

void UserApp::display()
{
    for(Graphics p:que)
    {
        p.draw();
        printf("\n");
    }
    return;
}

void UserApp::reshape(int indexG,int indexS,Point offset)
{
    que[indexG].getQue()[indexS]->reshape(offset);
    return;
}