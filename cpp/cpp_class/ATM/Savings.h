//
// Created by HBat on 2018/6/20.
//
#ifndef ATM_SAVINGS_H
#define ATM_SAVINGS_H

#include "Account.h"

class Savings:public Account
{
public:
    Savings(bool =false);//Flase is frozen
    Savings(std::string,std::string,std::string,std::string,double,bool =true);//Flase is frozen
    double save(const double &);
    double withdraw(const double &);
    const double & getbalance();
    bool setstate(bool);
    virtual std::string out();
    virtual std::string in(std::string);
private:
    double balance;
    bool state;
};

#endif //ATM_SAVINGS_H
