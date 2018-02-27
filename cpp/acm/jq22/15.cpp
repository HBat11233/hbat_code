//poj3268
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,x;
int map[1005][1005];
int dis[1005][2];
bool pk[1005];

int main()
{
    while(~scanf("%d%d%d",&n,&m,&x))
    {
        memset(dis,0x7f,sizeof(dis));
        memset(map,0x7f,sizeof(map));
        for(int i=1;i<=n;++i)
            map[i][i]=0;
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            scanf("%d",&map[a][b]);
        }
        memset(pk,0,sizeof(pk));
        queue<int>que;
        que.push(x);
        dis[x][0]=0;
        pk[x]=true;
        while(!que.empty())
        {
            int h=que.front();
            for(int i=1;i<=n;++i)
            {
                if(dis[i][0]>dis[h][0]+map[h][i])
                {
                    dis[i][0]=dis[h][0]+map[h][i];
                    if(!pk[i])
                    {
                        pk[i]=true;
                        que.push(i);
                    }
                }
            }
            que.pop();
            pk[h]=false;
        }
        memset(pk,0,sizeof(pk));
        dis[x][1]=0;
        que.push(x);
        pk[x]=true;
        while(!que.empty())
        {
            int h=que.front();
            for(int i=1;i<=n;++i)
            {
                if(dis[i][1]>dis[h][1]+map[i][h])
                {
                    dis[i][1]=dis[h][1]+map[i][h];
                    if(!pk[i])
                    {
                        pk[i]=true;
                        que.push(i);
                    }
                }
            }
            que.pop();
            pk[h]=false;
        }
        int ans=0;
        for(int i=1;i<=n;++i)
            ans=max(ans,dis[i][0]+dis[i][1]);
        printf("%d\n",ans);
    }
    return 0;
}