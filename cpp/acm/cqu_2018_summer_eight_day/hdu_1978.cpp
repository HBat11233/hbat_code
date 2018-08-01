//即使能量没耗完，也可以作为新的起点！！！
#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 10000
#define pb(a,b) (a>=0&&a<n&&b>=0&&b<m)

using namespace std;

int n,m;
int maps[105][105];
int dp[105][105];
int ans=0;

int dx[2]={0,1};
int dy[2]={1,0};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(maps,0,sizeof(maps));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                scanf("%d",&maps[i][j]);
        ans=0;
        dp[0][0]=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(dp[i][j])
                {
                    for(int x=0;x<=maps[i][j];++x)
                    {
                        for(int y=0;y<=maps[i][j];++y)
                        {
                            if(x==y&&y==0)continue;
                            if(x+y>maps[i][j])break;
                            int tx=x+i;
                            int ty=y+j;
                            if(pb(tx,ty))
                            {
                                dp[tx][ty]+=dp[i][j];
                                dp[tx][ty]%=INF;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[n-1][m-1]%INF);
    }
    return 0;
}

/*

3 2
3 2
4 5
2 2

*/