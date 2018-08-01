#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct ips
{
    int l;
    int r;
    int e;
    bool operator <(const ips &b)const
    {
        if(l==b.l)return r<b.r;
        else return l<b.l;
    }
}que[1005];

int dp[1000005];

int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int maxn=-1;
        for(int i=0;i<m;++i)
            scanf("%d%d%d",&que[i].l,&que[i].r,&que[i].e),maxn=max(maxn,que[i].r);
        memset(dp,0,sizeof(dp));
        sort(que,que+m);
        for(int i=0;i<m;++i)
        {
            int temp=(que[i].l-k>=0? dp[que[i].l-k]:0)+que[i].e;
            for(int j=que[i].r;j<=maxn;++j)
                dp[j]=max(dp[j],temp);
        }
        printf("%d\n",dp[maxn]);
    }
    return 0;
}