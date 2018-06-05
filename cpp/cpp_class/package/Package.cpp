#include "Package.h"
#include <stdexcept>

Package::Package(string sender,string recipient,string address,string city,string state,string zip_code,double weight,double cost)
:sender(sender),recipient(recipient),address(address),city(city),state(state),zip_code(zip_code),weight(weight>0? weight:0),cost(cost>0? cost:0)
{
    if(weight<0||cost<0)throw(std::invalid_argument("A double has to be greater than 0"));
}

double Package::calculateCost()
{
    return weight*cost;
}