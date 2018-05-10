#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int wt[70];
int num[70];
int top=0;
int dp[110][70][70];
char maps[110][20];
int mapwt[110];

bool pd(int &x)
{
    if(x&(x<<1))return 0;
    if(x&(x<<2))return 0;
    return 1;
}
int rd(int x)
{
    int jc=0;
    while(x)
    {
        if(x&1)jc++;
        x>>=1;
    }
    return jc;
}

int n,m;

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        int temp=1<<n;
        for(int i=0;i<temp;++i)
            if(pd(i))wt[++top]=i,num[top]=rd(i);
        memset(dp,-1,sizeof(dp));
        memset(maps,0,sizeof(maps));
        memset(mapwt,0,sizeof(mapwt));
        for(int i=1;i<=m;++i)scanf("%s",maps[i]+1);
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                if(maps[i][j]=='H')mapwt[i]|=(1<<(j-1));
        for(int i=1;i<=top;++i)
            if(!(wt[i]&mapwt[1]))dp[1][1][i]=num[i];
        for(int i=2;i<=m;++i)
        {
            for(int t=1;t<=top;++t)
            {
                if(wt[t]&mapwt[i])continue;
                for(int j=1;j<=top;++j)
                {
                    if(wt[t]&wt[j])continue;
                    for(int k=1;k<=top;++k)
                    {
                        if(wt[t]&wt[k])continue;
                        if(dp[i-1][k][j]==-1)continue;
                        dp[i][j][t]=max(dp[i][j][t],dp[i-1][k][j]+num[t]);
                    }
                }
            }
        }
        temp=0;
        for(int i=1;i<=m;++i)
        for(int j=1;j<=top;++j)
        for(int k=1;k<=top;++k)
        temp=max(temp,dp[i][j][k]);
        printf("%d\n",temp);
    }
    return 0;
}