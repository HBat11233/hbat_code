//
// Created by HBat on 2018/6/20.
//

#include "Savings.h"
#define ismon(td) (td*100!=(long long)(td*100))

Savings::Savings(bool state)
:state(state){}

Savings::Savings(std::string ac, std::string pa, std::string id, std::string na, double ba,bool state)
:Account(ac,pa,id,na),balance(ba),state(state)
{
    std::string str=getaccnum();
    int i;
    for(i=0;i<str.size();++i)
        if(str[i]<'0'||str[i]>'9')break;
    if(i!=19)
    {
        state=false;
        std::cerr<<"Account number is error!\n";
    }
    str=getpassage();
    for(i=0;i<str.size();++i)
        if(str[i]<'0'||str[i]>'9')break;
    if(i!=6)
    {
        state = false;
        std::cerr << "Passage number is error!\n";
    }
    str=geticard();
    for(i=0;i<str.size();++i)
        if(str[i]<'0'||str[i]>'9')break;
    if(i!=18&&i!=17)
    {
        state = false;
        std::cerr << "ID number is error!\n";
    }
    double td=this->balance;
    if(ismon(td))
    {
        state = false;
        std::cerr << "Balance number is error!\n";
    }
}

double Savings::save(const double & inmon)
{
    if(ismon(inmon))
            balance += inmon;
    else
        std::cerr<<"save number is error!\n";
    return balance;
}

double Savings::withdraw(const double & outmon)
{
    if(ismon(outmon))
        balance-=outmon;
    else
        std::cerr<<"save number is error!\n";
    return balance;
}

const double & Savings::getbalance()
{
    return balance;
}

std::string Savings::out()
{
    return Account::out()+"+"+std::to_string(balance)+"+"+(state? "1":"0");
}

std::string Savings::in(std::string com)
{
    com=Account::in(com);
    int pos[2]={-1,-1};
    for(int i=0,k=0;i<com.size()&&k<2;++i)
        if(com[i]=='+')
        {
            pos[k] = i;
            k++;
        }
    balance=stod(com.substr(0,pos[0]));
    state=(com.substr(pos[0]+1,pos[1]-pos[0]-1)=="1"? true:false);
    com=com.substr(pos[1]+1,com.size()-pos[1]-1);
    return com;
}

bool Savings::setstate(bool st)
{
    state=st;
    return state;
}