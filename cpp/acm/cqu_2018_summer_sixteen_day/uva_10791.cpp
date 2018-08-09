#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

map<int,LL>book;

int gcd(int a,int b)
{
    while(b)
    {
        int temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

LL solve(LL n)
{
    if(book.count(n))return book[n];
    LL t=n;
    LL sum=0;
    for(LL i=sqrt(n);i>1&&i!=n;--i)
    {
        if(n%i)continue;
        if(gcd(i,n/i)!=1)continue;
        LL a=solve(i),b=solve(n/i);
        sum+=min(i,a)+min(n/i,b);
        break;
    }
    if(sum==t)sum++;
    if(sum==0)sum=1+n;
    return book[n]=sum;
}

int main()
{
    int n;
    int o=0;
    while(scanf("%d",&n),n)
        printf("Case %d: %lld\n",++o,solve(n));
    return 0;
}