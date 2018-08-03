#include <iostream>
#include <cstdio>
#include <algorithm>

#define INF 100005

using namespace std;

int dp[200][200];

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
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=i;++j)
                scanf("%d",&dp[i][j]);
        for(int i=1;i<n;++i)
            for(int j=1;j<=n-i;++j)
                scanf("%d",&dp[n+i][j]);
        int temp=2*n;
        for(int i=2;i<=n;++i)
            for(int j=1;j<=i;++j)
            {
                if(j==1)
                    dp[temp-i][j]+=dp[temp-i+1][j];
                else if(j==i)
                    dp[temp-i][j]+=dp[temp-i+1][j-1];
                else
                    dp[temp-i][j]+=max(dp[temp-i+1][j],dp[temp-i+1][j-1]);
            }
        for(int i=n-1;i>=1;--i)
            for(int j=1;j<=i;++j)
                dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
        printf("Case %d: %d\n",o,dp[1][1]);
    }
    return 0;
}