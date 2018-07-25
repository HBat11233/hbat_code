#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long arr[1000005];
long long dp[1000005];


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        memset(dp,0,sizeof(dp));
        memset(arr,0,sizeof(arr));
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        dp[0]=arr[0];
        for(int i=1;i<n;++i)
        {
            dp[i]=(((dp[i-1]*arr[i])%MOD+arr[i])%MOD+dp[i-1])%MOD;
        }
        printf("%lld\n",dp[n-1]);
    }
    return 0;
}