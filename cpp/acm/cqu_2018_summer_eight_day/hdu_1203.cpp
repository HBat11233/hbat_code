#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 10005

using namespace std;

double dp[INF];
double ans[INF];
int w[INF];
double s[INF];
int n,m;

int main()
{
    while(scanf("%d%d",&n,&m),n+m)
    {
        for(int i=0;i<m;++i)
            scanf("%d%lf",w+i,s+i);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;++i)
            ans[i]=1;
        for(int i=0;i<m;++i)
        {
            for(int j=n;j>=w[i];--j)
            {
                if(dp[j]<dp[j-w[i]]+s[i])
                {
                    dp[j]=dp[j-w[i]]+s[i];
                    ans[j]=ans[j-w[i]]*(1-s[i]);
                }
            }
        }
        printf("%.1lf%%\n",(1-ans[n])*100);
    }
    return 0;
}