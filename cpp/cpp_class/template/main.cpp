#include "Vtype.h"

int main()
{
    Vtype<int> a(3,0);
    printf("%d",*a.begin());
    return 0;
}