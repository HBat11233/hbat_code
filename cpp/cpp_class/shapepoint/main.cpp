#include <iostream>
#include "UserApp.h"
#include "Point.h"

int main()
{
    UserApp e;
    e.init();
    e.display();
    e.reshape(0,0,Point(1.0,5.0));
    return 0;
}