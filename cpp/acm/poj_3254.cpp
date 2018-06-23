//状态压缩
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n,m;
short wt[400];
int top=0;
short maps[15][15];
short mapwt[15];
int dp[15][400][400];
const int MODNUM=100000000;

inline bool pd(const int &x)
{
    if(x&(x<<1))return false;
    return true;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        int temp=1<<n;
        for(int i=0;i<temp;++i)
            if(pd(i))wt[++top]=i;
        memset(dp,0,sizeof(dp));
        memset(maps,0,sizeof(maps));
        memset(mapwt,0,sizeof(mapwt));
        for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",maps[i]+j);
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                if(maps[i][j]==0)mapwt[i]+=(1<<(j-1));
        for(int i=1;i<=top;++i)
            if(!(wt[i]&mapwt[1]))dp[1][1][i]=1;
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
                        if(dp[i-1][k][j]==0)continue;
                        dp[i][j][t]+=dp[i-1][k][j]%MODNUM;
                        dp[i][j][t]%=MODNUM;
                    }
                }
            }
        }
        int &ans=temp;
        ans=0;
        for(int i=1;i<=top;++i)
        for(int j=1;j<=top;++j)
        {
            ans+=dp[m][i][j];
            ans%=MODNUM;
        }
        cout<<ans<<endl;
    }
}