//aoj0118
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int w,h;
char maps[101][101];
bool pmap[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans=0;

void dfs(int x,int y)
{
    for(int i=0;i<4;++i)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=0&&tx<h&&tx>=0&&ty<h&&maps[tx][ty]==maps[x][y]&&!pmap[tx][ty])
        {
            pmap[tx][ty]=true;
            dfs(tx,ty);
        }
    }
}

int main()
{
    while(scanf("%d%d",&h,&w),w+h)
    {
        memset(maps,0,sizeof(maps));
        memset(pmap,0,sizeof(pmap));
        for(int i=0;i<h;++i)
        {
            getchar();
            for(int j=0;j<w;++j)
            {
                scanf("%c",*(maps+i)+j);
            }
        }
        for(int i=0;i<h;++i)
        {
            for(int j=0;j<w;++j)
            {
                if(!pmap[i][j])
                {
                    pmap[i][j]=true;
                    ans++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}