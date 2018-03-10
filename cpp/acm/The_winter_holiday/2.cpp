//poj3009
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define xc tx+dx[i]
#define yc ty+dy[i]

using namespace std;

int w,h;
short maps[21][21];
int bx,by,ex,ey;
int minx=0x7fffffff;
int ans=1;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int x,int y)
{
    if(ans>10)return;
    for(int i=0;i<4;++i)
    {
        int tx=x+dx[i],ty=y+dy[i];
        if(tx>=0&&tx<w&&ty>=0&&ty<h&&maps[ty][tx]==1)continue;
        int k=0;
        do
        {
            k++;
            tx=x+dx[i]*k;
            ty=y+dy[i]*k;
            if(maps[ty][tx]==3)
            {
                minx=min(minx,ans);
                return;
            }
        }while(xc>=0&&xc<w&&yc>=0&&yc<h&&maps[yc][xc]!=1);
        if(xc>=0&&xc<w&&yc>=0&&yc<h&&maps[yc][xc]==1)
        {
            ans++;
            maps[yc][xc]=0;
            dfs(tx,ty);
            maps[yc][xc]=1;
            ans--;
        }
    }
    return;
}

int main()
{
    while(scanf("%d%d",&w,&h),w+h)
    {
        memset(maps,0,sizeof(maps));
        for(int i=0;i<h;++i)
        {
            for(int j=0;j<w;++j)
            {
                scanf("%d",*(maps+i)+j);
                if(maps[i][j]==2)bx=j,by=i;
                else if(maps[i][j]==3)ex=j,ey=j;
            }
        }
        minx=0x7fffffff;
        ans=1;
        dfs(bx,by);
        minx=minx>10? -1:minx;
        printf("%d\n",minx);
    }
    return 0;
}