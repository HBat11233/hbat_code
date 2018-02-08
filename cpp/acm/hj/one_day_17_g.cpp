#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct IP
{
    int x;
    int y;
    IP(const int x=-1,const int y=-1):
        x(x),y(y){}
    IP operator +(const IP &a)
    {
        IP ans(x+a.x,y+a.y);
        return ans;
    }
};

int maps[301][301];
bool sfa[301][301];
bool pmap[301][301];
const IP dip[4]={IP(0,1),IP(1,0),IP(0,-1),IP(-1,0)};

bool pq(IP &a)
{
    return (a.x>=0&&a.x<301&&a.y>=0&&a.y<301);
}

void pst(IP &a,bool p[][301])
{
    p[a.x][a.y]=true;
    for(int i=0;i<4;++i)
    {
        IP temp=a+dip[i];
        if(pq(temp))p[temp.x][temp.y]=true;
    }
}

int main()
{
    int n;
    int ans=0;
    IP p;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&p.x,&p.y);
        scanf("%d",&maps[p.x][p.y]);
        if(maps[p.x][p.y]==0)pst(p,pmap);
        pst(p,sfa);
    }
    if(pmap[0][0]){cout<<-1;return 0;}
    queue<IP>que;
    que.push(IP(0,0));
    int length=1;
    ans++;
    for(int i=0;i<301;++i)
        for(int j=0;j<301;++j)
        {
            maps[i][j]--;
            IP tt(i,j);
            if(maps[i][j]==0)pst(tt,pmap);
        }
    while(!que.empty())
    {
        IP head=que.front();
        if(!(length--))
        {
            length+=que.size();
            ans++;
            for(int i=0;i<301;++i)
                for(int j=0;j<301;++j)
                {
                    maps[i][j]--;
                    IP tt(i,j);
                    if(maps[i][j]==0)pst(tt,pmap);
                }
        }
        for(int i=0;i<4;++i)
        {
            IP temp=head + dip[i];
            if(!pq(temp))continue;
            if(!sfa[temp.x][temp.y])
            {
                cout<<ans;
                //system("pause");
                return 0;
            }
            if(!pmap[temp.x][temp.y])
            {
                pmap[temp.x][temp.y]=true;
                que.push(temp);
            }
        }
        que.pop();
    }
    cout<<-1;
    return 0;
}