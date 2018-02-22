//aoj0558
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

char maps[1001][1001];
int n;
int h,w;

struct IP
{
    int x;
    int y;
    IP(int x=0,int y=0):
        x(x),y(y){}
    bool operator ==(const IP &a)
    {
        if(x==a.x&&y==a.y)return true;
        else return false;
    }
}nu[10];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(IP &b,IP &e)
{
    int ans=0;
    queue<IP>que;
    bool pmap[1001][1001];
    for(int i=0;i<h;++i)
        for(int j=0;j<w;++j)
        {
            if(maps[i][j]=='X')pmap[i][j]=true;
            else pmap[i][j]=false;
        }
    que.push(b);
    pmap[b.x][b.y]=true;
    int leng=1;
    while(!que.empty())
    {
        IP he=que.front();
        if(leng==0)
        {
            ans++;
            leng=que.size();
        }
        if(he==e)break;
        for(int i=0;i<4;++i)
        {
            IP temp(he.x+dx[i],he.y+dy[i]);
            if(temp.x<0||temp.x>=h||temp.y<0||temp.y>=w||pmap[temp.x][temp.y])continue;
            pmap[temp.x][temp.y]=true;
            que.push(temp);
        }
        leng--;
        que.pop();
    }
    return ans;
}

int main()
{
    scanf("%d%d%d",&h,&w,&n);
    for(int i=0;i<h;++i)
    {
        getchar();
        for(int j=0;j<w;++j)
        {
            scanf("%c",*(maps+i)+j);
            if(maps[i][j]=='.'||maps[i][j]=='X')continue;
            if(maps[i][j]=='S')nu[0].x=i,nu[0].y=j;
            else nu[maps[i][j]-'0'].x=i,nu[maps[i][j]-'0'].y=j;
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
        ans+=bfs(nu[i],nu[i+1]);
    printf("%d\n",ans);
    return 0;
}