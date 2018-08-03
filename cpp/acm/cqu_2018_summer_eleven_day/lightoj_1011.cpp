#include <bits/stdc++.h>

#define INF 100005

using namespace std;

int dp[20][1<<17];//前i行，j状态的最大值
int maps[20][20];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);                                                 
#endif // DEBUG
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        int n;
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",&maps[i][j]);
        for(int i=0;i<n;++i)
            dp[1][1<<i]=maps[1][i+1];
        for(int i=2;i<=n;++i)
        {
            for(int j=0;j<n;++j)
            {
                for(int k=(1<<(i-1))-1;k<(1<<n);++k)
                {
                    if(!((1<<j)&k)&&dp[i-1][k])
                        dp[i][((1<<j)|k)]=max(dp[i][((1<<j)|k)],dp[i-1][k]+maps[i][j+1]);
                }
            }
        }
        int ans=-1;
        for(int i=(1<<n)-1;i<(1<<n);++i)
            ans=max(ans,dp[n][i]);
        printf("Case %d: %d\n",o,ans);
    }
    return 0;
}