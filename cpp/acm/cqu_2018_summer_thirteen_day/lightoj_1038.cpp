#include <bits/stdc++.h>

#define INF 100005

using namespace std;

double dp[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    dp[1]=0;
    dp[2]=2.0;
    double temp=0;
    for(int i=3;i<100001;++i)
    {
        temp=0;
        for(int j=1;j*j<=i;++j)
        {
            if(i%j!=0)continue;
            dp[i]+=dp[j];
            temp++;
            if(i/j!=j&&i/j!=i)
                dp[i]+=dp[i/j],temp++;
        }
        dp[i]=(dp[i]+temp+1)/temp;//temp为i的因子数-1，d[i] = ( d[1] + d[a2] + d[a3] + d[a4] ..... + d[i] + c) / c; (加c是因为每一个期望值都会加1,因为i多除一步才变成每个因子)
    }                              //上式化简而来。
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %.7f\n",o,dp[n]);
    }
    return 0;
}