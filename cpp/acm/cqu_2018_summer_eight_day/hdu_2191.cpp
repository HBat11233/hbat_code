#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 105

using namespace std;

int main()
{
    int c;
    scanf("%d",&c);
    while(c--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int quep[INF];
        int queh[INF];
        int quec[INF];
        for(int i=0;i<m;++i)
            scanf("%d%d%d",quep+i,queh+i,quec+i);
        int w[2005];
        int s[2005];
        int size=0;
        int dp[105];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;++i)
        {
            for(int j=1;j<quec[i];j<<=1)
            {
                w[size]=quep[i]*j;
                s[size++]=queh[i]*j;
                quec[i]-=j;
            }
            w[size]=quep[i]*quec[i];
            s[size++]=queh[i]*quec[i];
        }
        for(int i=0;i<size;++i)
            for(int j=n;j>=w[i];--j)
                dp[j]=max(dp[j-w[i]]+s[i],dp[j]);
        printf("%d\n",dp[n]);
    }
    return 0;
}