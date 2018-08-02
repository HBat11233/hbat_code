#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
double p;

struct ips
{
    int mn;
    double fx;
    ips(const int &mn=0,const int &fx=0)
    :mn(mn),fx(fx){}
    bool operator <(const ips &b)const
    {
        return fx<b.fx;
    }
}que[105];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%lf%d",&p,&n);
        int sums=0;
        int pos=0;
        for(int i=0;i<n;++i)
        {
            double temp;
            scanf("%d%lf",&que[pos].mn,&temp);
            que[pos].fx=1-temp;
            if(temp<p)sums+=que[pos].mn,pos++;
        }
        double dp[10005];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<pos;++i)
            for(int j=sums;j>=que[i].mn;--j)
                dp[j]=max(dp[j],dp[j-que[i].mn]*que[i].fx);
        int ans;
        for(int i=sums;i>=0;--i)
                if(dp[i]>1-p&&dp[i]!=0)
                {
                    ans=i;
                    break;
                }
        printf("%d\n",ans);
    }
    return 0;
}