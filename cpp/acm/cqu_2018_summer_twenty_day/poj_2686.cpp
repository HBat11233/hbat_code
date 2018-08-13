#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int,int>pa;

int n,m,p,a,b;
double piao[10];
int w[35][35];
double dp[1<<9][35];

void spfa(int x)
{
    queue<pa>que;
    bool pk[1<<9][35];
    memset(pk,0,sizeof(pk));
    dp[0][x]=0;
    pk[0][x]=true;
    que.push(pa(0,x));
    while(!que.empty())
    {
        pa h=que.front();
        for(int i=0;i<n;++i)
        {
            if(h.first & (1<<i))continue;
            int ws = h.first | (1<<i);
            for(int j=1;j<=m;++j)
            {
                if(w[h.second][j]>=0x7f7f7f7f)continue;
                if(dp[ws][j]>dp[h.first][h.second]+w[h.second][j]/piao[i])
                {
                    dp[ws][j]=dp[h.first][h.second]+w[h.second][j]/piao[i];
                    if(!pk[ws][j])
                    {
                        pk[ws][j]=true;
                        que.push(pa(ws,j));
                    }
                }
            }
        }
        que.pop();
        pk[h.first][h.second]=false;
    }
}

int main()
{
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b),n+m+p+a+b)
    {
        for(int i=0;i<n;++i)
            scanf("%lf",piao+i);
        memset(w,0x7f,sizeof(w));
        for(int i=0;i<p;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            w[a][b]=w[b][a]=c;
        }
        memset(dp,0x7f,sizeof(dp));
        for(int i=0;i<(1<<n);++i)
            dp[i][a]=0;
        spfa(a);
        double ans=0x7fffffff;
        for(int i=0;i<(1<<n);++i)
            ans=min(ans,dp[i][b]);
        if(ans>=0x7f7f7f7f)cout<<"Impossible\n";
        else cout<<ans<<'\n';
    }
    return 0;
}