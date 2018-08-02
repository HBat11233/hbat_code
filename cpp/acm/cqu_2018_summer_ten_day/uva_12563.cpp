#include <bits/stdc++.h>

#define INF 10005
#define JQ 678

using namespace std;

struct ips
{
    int num;
    int sum;
    ips operator +(const int &b)
    {
        ips a;
        a.num=num+1;
        a.sum=sum+b;
        return a;
    }
    bool operator <(const ips &b)const
    {
        if(num==b.num)return sum<b.sum;
        else return num<b.num;
    }
}dp[INF];

int w[60];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        memset(w,0,sizeof(w));
        for(int i=0;i<n;++i)
            scanf("%d",w+i);
        w[n]=JQ;
        for(int i=0;i<n;++i)
            for(int j=m-1;j>=w[i];--j)
            dp[j]=max(dp[j-w[i]]+w[i],dp[j]);
        ips a;
        a=dp[m-1]+JQ;
        printf("Case %d: %d %d\n",o,a.num,a.sum)
    }
    return 0;
}