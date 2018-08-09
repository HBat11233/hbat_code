#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long long LL;

using namespace std;

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

inline LL lcm(LL a,LL b,LL gc)
{
    return a/gc*b;
}

int main()
{
    LL a,b;
    while(~scanf("%lld%lld",&a,&b))
    {
        LL ansgcd=gcd(a,b);
        LL anslcm=lcm(a,b,ansgcd);
        printf("%d %d\n",ansgcd,anslcm);
    }
    return 0;
}