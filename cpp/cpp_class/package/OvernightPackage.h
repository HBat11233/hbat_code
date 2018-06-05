#ifndef OVERNIGTHPACKAGE_H
#define OVERNIGTHPACKAGE_H

#include "Package.h"
#include <iostream>
using std::string;

class OvernightPackage:public Package
{
public:
    OvernightPackage(string ="",string ="",string ="",string ="",string ="",string ="",double =0,double =0,double =0);
    virtual ~OvernightPackage() =default;
    virtual double calculateCost();
private:
    double ffee;
};

#endif