#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define pb(a,b) (a>=0&&a<n&&b>=0&&b<n)

using namespace std;

int n,m;
int maps[104][104];
int dp[104][104];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int dfs(int x,int y)
{
    int maxn=0;
    if(dp[x][y]>0)return dp[x][y];
    int tx,ty;
    for(int i=0;i<4;++i)
    {
        for(int j=1;j<=m;++j)
        {
            int tx=dx[i]*j+x;
            int ty=dy[i]*j+y;
            if(pb(tx,ty)&&maps[x][y]<maps[tx][ty])
            {
                int temp=dfs(tx,ty);
                maxn=temp>maxn? temp:maxn;
            }
        }
    }
    dp[x][y]=maxn+maps[x][y];
    return dp[x][y];

}

int main()
{
    while(scanf("%d%d",&n,&m),~n&&~m)
    {
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                 scanf("%d",&maps[i][j]);
        memset(dp,0,sizeof(dp));
        cout<<dfs(0,0)<<endl;
    }
    return 0;
}