//hdu1312
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char map[21][21];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int a,b;
int ans=1;

void dfs(int &x,int &y)
{
    for(int i=0;i<4;++i)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=0&&ty>=0&&tx<a&&ty<=b&&map[ty][tx]=='.')
        {
            ans++;
            map[ty][tx]='#';
            dfs(tx,ty);
        }
    }
    return;
}

int main()
{
    while(scanf("%d%d",&a,&b),a+b)
    {
        memset(map,0,sizeof(map));
        int x,y;
        for(int i=0;i<b;++i)
        {
            getchar();
            for(int j=0;j<a;++j)
            {
                scanf("%c",*(map+i)+j);
                if(map[i][j]=='@')x=j,y=i;
            }
        }
        dfs(x,y);
        printf("%d\n",ans);
        ans=1;
    }
    return 0;
}