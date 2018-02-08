#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int maps[101][101];

int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool smap[101][101];
int answer[101][101];

int dfs(int x,int y,int ans)
{
    if(answer[x][y]!=-1)return answer[x][y];
    int len=-1;
    for(int i=0;i<4;++i)
    {
        
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=1&&ty>=1&&tx<=n&&ty<=m)
        {
            if(maps[x][y]>maps[tx][ty])
            {
                len=max(len,dfs(tx,ty,ans+1));
            }
        }
        
    }
    if(len!=-1)
    {
        answer[x][y]=len+1;
        return len+1;
    }
    answer[x][y]=1;
    return 1;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>maps[i][j];
    memset(answer,-1,sizeof(answer));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            dfs(i,j,0);
        }
    }
    int ans=-1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            ans=max(ans,answer[i][j]);
    cout<<ans;
    return 0;
}