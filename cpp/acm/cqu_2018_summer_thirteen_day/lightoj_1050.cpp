#include <bits/stdc++.h>

#define INF 600

using namespace std;

double dp[INF][INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    for(int i=0;i<=500;++i)
            dp[0][i]=1;
    for(int i=1;i<=500;++i)
        for(int j=1;j<=500;++j)
            dp[i][j]=dp[i-1][j-1]*((double)i/((double)i+(double)j))+dp[i][j-2]*((double)j/((double)i+(double)j));
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        int r,b;
        scanf("%d%d",&r,&b);
        printf("Case %d: %.7f\n",o,dp[r][b]);
    }
    return 0;
}