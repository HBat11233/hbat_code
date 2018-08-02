#include <bits/stdc++.h>

#define INF 100005

using namespace std;

int dp[60][300];
int t[60];
bool m1t[60][300];
bool m2t[60][300];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n;
    int T;
    int o=0;
    while(scanf("%d",&n),n)
    {
        memset(m1t,0,sizeof(m1t));
        memset(m2t,0,sizeof(m2t));
        memset(t,0,sizeof(t));
        scanf("%d",&T);
        for(int i=1;i<n;++i)
            scanf("%d",&t[i]);
        int m1,m2;
        scanf("%d",&m1);
        for(int i=0;i<m1;++i)
        {
            int te;
            scanf("%d",&te);
            for(int j=1;j<=n;++j)
            {
                m1t[j][te]=true;
                te+=t[j];
            }
        }
        scanf("%d",&m2);
        for(int j=0;j<m2;++j)
        {
            int te;
            scanf("%d",&te);
            for(int j=n;j>=1;--j)
            {
                m2t[j][te]=true;
                te+=t[j-1];
            }
        }
        memset(dp,0x3f,sizeof(dp));
        dp[n][T]=0;
        for(int j=T-1;j>=0;--j)
        {
            for(int i=1;i<=n;++i)
            {
                dp[i][j]=dp[i][j+1]+1;
                if(m1t[i][j])dp[i][j]=min(dp[i][j],dp[i+1][j+t[i]]);
                if(m2t[i][j])dp[i][j]=min(dp[i][j],dp[i-1][j+t[i-1]]);
            }
        }
        printf("Case Number %d: ",++o);
        if(dp[1][0]>T)printf("impossible\n");
        else printf("%d\n",dp[1][0]);
    }
    return 0;
}