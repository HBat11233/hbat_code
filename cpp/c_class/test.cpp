#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1234;
    int ans=0;
    while(a!=0)
    {
        ans*=10;
        ans+=a%10;
        a/=10;
    }
    printf("%d\n",ans);
    system("color F1");
    system("pause");
    return 0;
}