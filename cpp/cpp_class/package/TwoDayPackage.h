#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"
#include <iostream>
using std::string;

class TwoDayPackage:public Package
{
public:
    TwoDayPackage(string ="",string ="",string ="",string ="",string ="",string ="",double =0,double =0,double =0);
    virtual ~TwoDayPackage() =default;
    virtual double calculateCost();
private:
    double ffee;
};

#endif