#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct ips
{
    int x;
    int y;
    ips(int x=0,int y=0)
    :x(x),y(y){}
    bool operator < (const ips & b)const
    {
        return x==b.x? y<b.y:x<b.x;
    }
    bool operator <= (const ips &b)const
    {
        return y<=b.y&&x<=b.x;
    }
}da[20];

int dp[1<<15];
int pk[1<<15];
int fg[15][15];

inline int mul(int pos1,int pos2)
{
    int dx=max(1,abs(da[pos1].x-da[pos2].x));
    int dy=max(1,abs(da[pos1].y-da[pos2].y));
    return dx*dy;
}

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        memset(dp,0x7f,sizeof(dp));
        memset(pk,0,sizeof(pk));
        memset(fg,0,sizeof(fg));
        for(int i=0;i<n;++i)
            scanf("%d%d",&da[i].x,&da[i].y);
        sort(da,da+n);
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
            {
                ips ma(max(da[i].x,da[j].x),max(da[i].y,da[j].y));
                ips mi(min(da[i].x,da[j].x),min(da[i].y,da[j].y));
                for(int k=0;k<n;++k)
                    if(mi<=da[k]&&da[k]<=ma)
                        fg[i][j]|=(1<<k);
                fg[j][i]=fg[i][j];
            }
        queue<int>que;
        que.push(0);
        dp[0]=0;
        while(!que.empty())
        {
            int w=que.front();
            for(int i=0;i<n;++i)
            {
                for(int j=i+1;j<n;++j)
                {
                    if((w & (1<<i)) && (w & (1<<j)))continue;
                    int t=w|fg[i][j];
                    if(dp[t]>dp[w]+mul(i,j))
                    {
                        dp[t]=dp[w]+mul(i,j);
                        if(!pk[t])
                        {
                            pk[t]=true;
                            que.push(t);
                        }
                    }
                }
            }
            que.pop();
            pk[w]=false;
        }
        cout<<dp[(1<<n)-1]<<'\n';
    }
    return 0;
}