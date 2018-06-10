#include <iostream>
#include <vector>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

typedef Package P;
typedef TwoDayPackage T;
typedef OvernightPackage O;

int main()
{
    P pt("why","csw","ccdx","cqs","cq","400021",15,6);
    T py("wdc","why","ccdx","cqs","cq","400021",15,6,3.6);
    O pu("wdc","csw","ccdx","cqs","cq","400021",14,8,2.5);
    vector <P *> ptr;
    cout<<pt.calculateCost()<<endl;
    cout<<py.calculateCost()<<endl;
    cout<<pu.calculateCost()<<endl;
    ptr.push_back(&pt);
    ptr.push_back(&py);
    ptr.push_back(&pu);
    for(P* i:ptr)
        cout<<i->calculateCost()<<endl;
    return 0;
}