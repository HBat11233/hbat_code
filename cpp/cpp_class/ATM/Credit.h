//
// Created by HBat on 2018/6/20.
//

#ifndef ATM_CREDIT_H
#define ATM_CREDIT_H

#include "Account.h"

class Credit:public Account
{
public:
    Credit(bool =false);
    Credit(std::string,std::string,std::string,std::string, double, double, bool=true);
    double borrow(const double &);
    double repay(const double &);
    double getliabilities();
    double getlines();
    bool setstate(bool);
    virtual std::string out();
    virtual std::string in(std::string);
private:
    double liabilities;
    double lines;
    bool state;
};

#endif //ATM_CREDIT_H
