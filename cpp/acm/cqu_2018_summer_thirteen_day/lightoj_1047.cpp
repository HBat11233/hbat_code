#include <bits/stdc++.h>

#define INF 25

using namespace std;

int dp[INF][3];
int que[INF][3];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        memset(dp,0,sizeof(dp));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d%d%d",&que[i][0],&que[i][1],&que[i][2]);
        dp[0][0]=que[0][0];
        dp[0][1]=que[0][1];
        dp[0][2]=que[0][2];
        for(int i=1;i<n;++i)
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+que[i][0];
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+que[i][1];
            dp[i][2]=min(dp[i-1][1],dp[i-1][0])+que[i][2];
        }
        int ans=0x7fffffff;
        ans=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
        printf("Case %d: %d\n",o,ans);
    }
    return 0;
}