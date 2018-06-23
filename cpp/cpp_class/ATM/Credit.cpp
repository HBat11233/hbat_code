//
// Created by HBat on 2018/6/20.
//
#include "Credit.h"
#define ismon(td) (td*100==(long long)(td*100))

Credit::Credit(bool state)
:state(state)
{}

Credit::Credit(std::string ac, std::string ps, std::string id, std::string na, double lia, double lin, bool sta)
:Account(ac,ps,id,na),liabilities(lia),lines(lin),state(sta)
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
    double td=this->liabilities;
    if(ismon(td))
    {
        state = false;
        std::cerr << "Liabilities number is error!\n";
    }
    td=this->lines;
    if(ismon(td))
    {
        state = false;
        std::cerr << "Lines number is error!\n";
    }
}

double Credit::getliabilities()
{
    return liabilities;
}

double Credit::getlines()
{
    return lines;
}

double Credit::borrow(const double & num)
{
    if(ismon(num))
        liabilities+=num;
    else
        std::cerr<<"borrow number is error!\n";
    return liabilities;
}

double Credit::repay(const double & num)
{
    if(ismon(num))
        liabilities-=num;
    else
        std::cerr<<"repay number is error!\n";
    return liabilities;
}

std::string Credit::out()
{
    return Account::out()+"+"+std::to_string(liabilities)+"+"+std::to_string(lines)+"+"+(state? "1":"0");
}
std::string Credit::in(std::string com)
{
    com=Account::in(com);
    int pos[3]={-1,-1,-1};
    for(int i=0,k=0;i<com.size()&&k<3;++i)
        if(com[i]=='+')
        {
            pos[k] = i;
            k++;
        }
    liabilities=stod(com.substr(0,pos[0]));
    lines=stod(com.substr(pos[0]+1,pos[1]-pos[0]-1));
    state=(com.substr(pos[1]+1,pos[2]-pos[1]-1)=="1"? true:false);
    com=com.substr(pos[1]+1,com.size()-pos[1]-1);
    return com;
}

bool Credit::setstate(bool st)
{
    state=st;
    return state;
}