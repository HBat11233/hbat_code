//
// Created by HBat on 2018/6/20.
//

#include "Bank.h"
#include <fstream>
#include <typeinfo>

Bank::Bank()
{
    fin();
}

Bank::~Bank()
{
    fout();
    while(que.size())
    {
        delete(*que.rbegin());
        que.pop_back();
    }
}

void Bank::fout(std::string strip)
{
    std::fstream f;
    f.open(strip,std::ios::out);
    for(int i=0;i<que.size();++i)
    {
        if(typeid(*que[i]).name()==typeid(Savings).name())
            f<<"S"<<std::endl;
        else
            f<<"C"<<std::endl;
        f<<que[i]->out()<<std::endl;
    }
    f.close();
    return;
}

void Bank::fin(std::string strip)
{
    std::fstream f;
    f.open(strip,std::ios::in);
    std::string str;
    while(f>>str)
    {
        if(str=="S")
        {
            f>>str;
            que.push_back(NULL);
            *que.rbegin()=new Savings;
            (*que.rbegin())->in(str);
        }else if(str=="C")
        {
            f>>str;
            que.push_back(NULL);
            *que.rbegin()=new Credit;
            (*que.rbegin())->in(str);
        } else
            std::cerr<<"file error!\n";
    }
    f.close();
    return;
}

Account * Bank::find(std::string accnum)
{
    for(int i=0;i<que.size();++i)
        if(que[i]->getaccnum()==accnum)
            return que[i];
    return NULL;
}

void Bank::add(Credit a)
{
    que.push_back(NULL);
    *que.rbegin()=new Credit(a);
}

void Bank::add(Savings a)
{
    que.push_back(NULL);
    *que.rbegin()=new Savings(a);
}