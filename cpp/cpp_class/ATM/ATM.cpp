//
// Created by HBat on 2018/6/21.
//

#include "ATM.h"
#include "Credit.h"
#include "Savings.h"
#include <typeinfo>

ATM::ATM()
{
}

void ATM::run()
{
    std::cout<<"============================\n";
    std::cout<<"   Welcome to HBat ATM!\n";
    std::cout<<"   1.use.        2.quit.\n";A1:
    std::cout<<"         1 or 2    \n";
    int num;
    std::cin>>num;
    switch (num)
    {
        case 1:
            insertc();
            returnc();
            break;
        case 2:
            break;
        default:
            std::cout<<"error!\n";
            goto A1;
    }
    std::cout<<"Welcome to use next time\n";
    std::cout<<"============================\n";
    return;
}

void ATM::insertc()
{
    std::string accnum;
    std::string passage;
    Account *acc;
    do
    {
        std::cout << "input e to exit!\n";
        std::cout << "input account number:";
        std::cin >> accnum;
        if(accnum=="e")return;
        acc = bank.find(accnum);
        if (acc == NULL)
            std::cout << "Account number does not exist!\n";
    }while (acc==NULL);
    bool isS;
    if(typeid(*acc).name()== typeid(Savings).name())isS=true;
    else isS=false;
    do
    {
        static int p=0;
        std::cout<<"input passage number:";
        std::cin>>passage;
        bool pk=acc->Verify(passage);
        p++;
        if(!pk)std::cout<<"You have "<<6-p<<" more chances\n";
        if(p==6&&!pk)
        {
            std::cout<<"Account is frozen!\n";
            isS? ((Savings *)acc)->setstate(false):((Credit *)acc)->setstate(false);//设计上的bug，在account时应该设计state
            return;
        }
        if(pk)break;
    }while(true);

    switch (isS)
    {
        case true:
            Scard((Savings *)acc);
            break;
        case false:
            Ccard((Credit *)acc);
            break;
    }
    return;
}

void ATM::Scard(Savings * acc)
{
    int num=0,money;
    std::cout<<"----------------------------\n";
    std::cout<<"1.save   2.withdraw   3.quit\n";
    do
    {
        std::cout << "         1 ,2 or 3\n";
        std::cin>>num;
        switch (num)
        {
            case 1:
                do
                {
                    std::cout << "save number:";
                    std::cin >> money;
                    if(money % 100)
                    std::cerr << "It has to be a multiple of 100.\n";
                }while (money % 100);
                acc->save(money);
                break;
            case 2:
                do
                {
                    std::cout << "withdraw number:";
                    std::cin >> money;
                    if(money % 100)
                        std::cerr << "It has to be a multiple of 100.\n";
                }while (money % 100);
                if(money>acc->getbalance())std::cout<<"Lack of balance\n";
                else acc->withdraw(money);
                break;
            case 3:
                return;
            default:
                num=0;
                break;
        }
    }while (num!=0);
    return;
}

void ATM::Ccard(Credit * acc)
{
    int num=0,money;
    std::cout<<"----------------------------\n";
    std::cout<<"1.brrow   2.repay   3.quit\n";
    do
    {
        std::cout << "      1 ,2 or 3\n";
        std::cin>>num;
        switch (num)
        {
            case 1:
                do
                {
                    std::cout << "borrow number:";
                    std::cin >> money;
                    if(money % 100)
                        std::cerr << "It has to be a multiple of 100.\n";
                }while (money % 100);
                acc->borrow(money);
                break;
            case 2:
                do
                {
                    std::cout << "repay number:";
                    std::cin >> money;
                    if(money % 100)
                        std::cerr << "It has to be a multiple of 100.\n";
                }while (money % 100);
                if(money>(acc->getlines())-(acc->getliabilities()))std::cout<<"Lack of balance\n";
                else acc->repay(money);
                break;
            case 3:
                return;
            default:
                num=0;
                break;
        }
    }while (num!=0);
    return;
}

void ATM::returnc()
{
    std::cout<<"Please take your card!\n";
}