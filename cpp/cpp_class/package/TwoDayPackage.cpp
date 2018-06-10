#include "TwoDayPackage.h"
#include <stdexcept>

TwoDayPackage::TwoDayPackage(string sender,string recipient,string address,string city,string state,string zip_code,double weight,double cost,double ffee)
:Package(sender,recipient,address,city,state,zip_code,weight,cost),ffee(ffee)
{
    if(ffee<0)throw(std::invalid_argument("A double has to be greater than 0"));
}

double TwoDayPackage::calculateCost()
{
    return Package::calculateCost()+ffee;
}