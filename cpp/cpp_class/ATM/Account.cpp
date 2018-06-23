//
// Created by HBat on 2018/6/20.
//
#include "Account.h"

Account::Account(){}

Account::Account(std::string accnum, std::string passage, std::string idcard, std::string name)
:accnum(accnum),passage(passage),idcard(idcard),name(name) {}

Account::~Account() {}

bool Account::Verify(const std::string ipassage)
{
    return passage==ipassage;
}

std::string Account::out()
{
    return accnum+"+"+passage+"+"+idcard+"+"+name;
}

std::string Account::in(std::string com)
{
    int pos[4]={-1,-1,-1,-1};
    for(int i=0,k=0;i<com.size()&&k<4;++i)
        if(com[i]=='+')
        {
            pos[k] = i;
            k++;
        }
    accnum=com.substr(0,pos[0]);
    passage=com.substr(pos[0]+1,pos[1]-pos[0]-1);
    idcard=com.substr(pos[1]+1,pos[2]-pos[1]-1);
    name=com.substr(pos[2]+1,pos[3]-pos[2]-1);
    com=com.substr(pos[3]+1,com.size()-pos[3]-1);
    return com;
}

std::string const & Account::getaccnum()
{
    return accnum;
}

std::string const & Account::getpassage()
{
    return passage;
}

std::string const & Account::geticard()
{
    return idcard;
}

std::string const & Account::getname()
{
    return name;
}