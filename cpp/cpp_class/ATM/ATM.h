//
// Created by HBat on 2018/6/21.
//

#ifndef ATM_ATM_H
#define ATM_ATM_H

#include "Bank.h"
#include <vector>
#include <iostream>

class ATM
{
public:
    ATM();
    void run();
    void insertc();
    void returnc();
    void Scard(Savings *);
    void Ccard(Credit *);
private:
    Bank bank;
};

#endif //ATM_ATM_H
