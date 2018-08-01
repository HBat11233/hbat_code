#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n,w;
    while(~scanf("%d%d",&n,&w))
    {
        int dp[2][34];//dp[i][j],在i+1树下，剩余交换次数j，，
        memset(dp,0,sizeof(dp));
        int temp;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&temp);
            dp[temp-1][w]++;
            for(int j=w-1;j>=0&&i+j+1>w;--j)
                dp[temp-1][j]=max(dp[!(temp-1)][j+1]+1,dp[temp-1][j]+1);//这棵树前一次掉苹果，和另一棵树前一次交换掉苹果。
        }
        int ans=-1;
        for(int i=0;i<2;++i)
            for(int j=0;j<=w;++j)
                ans=max(ans,dp[i][j]);
        printf("%d\n",ans);
    }
    return 0;
}