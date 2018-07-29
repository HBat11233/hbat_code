#include <bits/stdc++.h>

using namespace std;

struct ips
{
    long long x;
    long long y;
    long long num;
    bool operator <(const ips &b)const
    {
        long long sum1=x*x+y*y;
        long long sum2=b.x*b.x+b.y*b.y;
        return sum1<sum2;
    }
}que[1005];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,s;
    while(~scanf("%d%d",&n,&s))
    {
        for(int i=0;i<n;++i)
            scanf("%lld%lld%lld",&que[i].x,&que[i].y,&que[i].num);
        sort(que,que+n);
        long long sum=s;
        int i=0;
        for(i=0;i<n&&sum<1000000;++i)
            sum+=que[i].num;
        i--;
        if(sum<1000000&&i==n-1)
        printf("-1\n");
        else
        printf("%.9llf\n",sqrt(que[i].x*que[i].x+que[i].y*que[i].y));
    }
    return 0;
}