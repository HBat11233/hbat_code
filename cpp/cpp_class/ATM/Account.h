//
// Created by HBat on 2018/6/20.
//

#ifndef ATM_ACCOUNT_H
#define ATM_ACCOUNT_H

#include <iostream>

class Account
{
public:
    Account();
    Account(std::string,std::string,std::string,std::string);
    virtual ~Account();
    bool Verify(const std::string);
    std::string const & getaccnum();
    std::string const & getpassage();
    std::string const & geticard();
    std::string const & getname();
    virtual std::string out();
    virtual std::string in(std::string);
private:
    std::string accnum;
    std::string passage;
    std::string idcard;
    std::string name;
};

#endif //ATM_ACCOUNT_H
