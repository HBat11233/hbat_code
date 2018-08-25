#include <bits/stdc++.h>
#include <cstdio>

#define INF 505
#define pk(x,y) (x>=1&&x<=n&&y>=1&&y<=m)

using namespace std;

int n,m;
int maps[INF][INF];
int ex,ey;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int bfs(int x,int y)
{
    queue<int>qx,qy;
    qx.push(x);
    qy.push(y);
    while(!qx.empty())
    {
        int cx=qx.front();
        int cy=qy.front();
        qx.pop();
        qy.pop();
        for(int i=0;i<4;++i)
        {
            int tx=cx+dx[i];
            int ty=cy+dy[i];
            if(pk(tx,ty))
            {
                if(maps[tx][ty]&&tx==ex&&ty==ey)return 1;
                else if(!maps[tx][ty])
                {
                    maps[tx][ty]=1;
                    qx.push(tx);
                    qy.push(ty);
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    while(cin>>n>>m)
    {
        memset(maps,0,sizeof(maps));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                char ch;
                cin>>ch;
                if(ch=='X')maps[i][j]=1;
            }
        }
        int bx,by;
        cin>>bx>>by>>ex>>ey;
        if(bfs(bx,by))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}