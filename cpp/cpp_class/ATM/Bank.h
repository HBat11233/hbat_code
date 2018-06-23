//
// Created by HBat on 2018/6/20.
//

#ifndef ATM_BANK_H
#define ATM_BANK_H

#include <vector>
#include "Account.h"
#include "Savings.h"
#include "Credit.h"

class Bank
{
public:
    Bank();
    ~Bank();
    void fin(std::string ="data.d");
    void fout(std::string ="data.d");
    Account * find(std::string);
    void add(Savings);
    void add(Credit);
    void add(Account);
private:
    std::vector<Account *>que;
};

#endif //ATM_BANK_H
