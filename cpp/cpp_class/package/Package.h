#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

using std::string;

class Package
{
public:
    Package(string ="",string ="",string ="",string ="",string ="",string ="",double =0,double =0);
    virtual ~Package() =default;
    virtual double calculateCost();
private:
    string sender;
    string recipient;
    string address;
    string city;
    string state;
    string zip_code;
    double weight;
    double cost;
};

#endif