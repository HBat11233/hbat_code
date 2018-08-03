#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

long long dp[50][1000];
long long c[50][50];

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=30;++i)
        c[i][1]=i;
    for(int i=2;i<=30;++i)
        for(int j=2;j<=i;++j)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    for(int i=1;i<=30;++i)
        dp[i][1]=i*i,dp[i][0]=1;
    for(int i=2;i<=30;++i)
        dp[i][i]=i*dp[i-1][i-1];
    for(int i=2;i<=30;++i)
        for(int j=2;j<=i;++j)
            dp[i][j]=c[i][j]*c[i][j]*dp[j][j];
    for(int o=1;o<=t;++o)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        printf("Case %d: %lld\n",o,dp[n][k]);
    }
    return 0;
}