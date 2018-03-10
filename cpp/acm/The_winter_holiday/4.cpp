//poj3669
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
#include <cstdio>

using namespace std;

int maps[313][313];
int le[313][313];
int m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs()
{
    bool mp[313][313];
    memset(mp,0,sizeof(mp));
    queue<int>quex,quey;
    quex.push(0);
    quey.push(0);
    mp[0][0]=true;
    while(!quex.empty())
    {
        int hx=quex.front();
        int hy=quey.front();
        if(maps[hx][hy]==-1)
        {
            cout<<le[hx][hy]<<endl;
            return;
        }
        for(int i=0;i<4;++i)
        {
            int tx=hx+dx[i];
            int ty=hy+dy[i];
            if(tx<0||ty<0)continue;//不能有上边界，跑出去也算，不能按数据范围来看
            le[tx][ty]=le[hx][hy]+1;
            if(!mp[tx][ty]&&(maps[tx][ty]>le[tx][ty]||maps[tx][ty]==-1))
            {
                quex.push(tx);
                quey.push(ty);
                mp[tx][ty]=true;
            }
            
        }
        quex.pop();
        quey.pop();
    }
    cout<<-1<<endl;
    return;
}

int main()
{
    while(~scanf("%d",&m))
    {
        memset(maps,-1,sizeof(maps));
        memset(le,0,sizeof(le));
        //ans=1;
        for(int i=0;i<m;++i)
        {
            int x,y;
            int t;
            scanf("%d%d%d",&x,&y,&t);
            maps[x][y]=maps[x][y]<0?t:min(maps[x][y],t);
            for(int i=0;i<4;++i)
            {
                int sx=abs(x+dx[i]);
                int sy=abs(y+dy[i]);
                maps[sx][sy]=maps[sx][sy]<0?t:min(maps[sx][sy],t);
            }
        }
        bfs();
    }
    return 0;
}

/*
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int map[310][310];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int mark[310][310];
struct node
{
	int x,y,step;
}temp,a;
bool operator < (const node &a,const node &b)
{
	return a.step>b.step;
} 

int min(int a,int b)
{
	return a>b?b:a;
}

void bfs()
{
	int i;
	memset(mark,0,sizeof(mark));
	priority_queue<node>q;
	a.x=0;
	a.y=0;
	a.step=0;
	q.push(a);
	mark[0][0]=1;
	while(!q.empty())
	{
		a=q.top();
		q.pop();
		if(map[a.x][a.y]==-1)
		{
			printf("%d\n",a.step);
			return ;
		}
		for(i=0;i<4;++i)
		{
			temp.x=a.x+dir[i][0];
			temp.y=a.y+dir[i][1];
			temp.step=a.step+1;
			if(temp.x>=0&&temp.y>=0&&(map[temp.x][temp.y]==-1||map[temp.x][temp.y]>temp.step))
			{
				if(!mark[temp.x][temp.y])
				q.push(temp);
				mark[temp.x][temp.y]=1;
			}
		}
	}
	printf("-1\n");
}



int main()
{
	int n,x,y,t,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		memset(map,-1,sizeof(map));
		for(i=0;i<n;++i)
		{
			scanf("%d%d%d",&x,&y,&t);
			if(map[x][y]==-1)//判断是否受过撞击时间的更新 
				map[x][y]=t;
			else
				map[x][y]=min(map[x][y],t);//受过撞击后的点不能再走了 
			for(j=0;j<4;++j)
			{
				int nx=x+dir[j][0];
				int ny=y+dir[j][1];
				if(nx>=0&&ny>=0)
				{
					if(map[nx][ny]==-1)
						map[nx][ny]=t;
					else
						map[nx][ny]=min(t,map[nx][ny]); 
				}
			}
		}
		bfs();
	}
	return 0;
} 
*/