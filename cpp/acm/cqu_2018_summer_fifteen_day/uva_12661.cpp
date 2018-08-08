#include <bits/stdc++.h>

using namespace std;

int n,m,s,t;
struct ips
{
    int n;
    int o;
    int c;
    int r;
    ips(int n=0,int o=0,int c=0,int r=0)
    :n(n),o(o),c(c),r(r){}
};
vector< vector<ips> >da;
int dis[400];
int pk[400];

void spfa(int x)
{
    memset(dis,0x7f,sizeof(dis));
    memset(pk,0,sizeof(pk));
    queue<int>que;
    que.push(x);
    pk[x]=true;
    dis[x]=0;
    while(!que.empty())
    {
        int h=que.front();
        for(int j=0;j<da[h].size();++j)
        {
            int sy=dis[h]%(da[h][j].o+da[h][j].c);
            int dt=0;
            if(sy>da[h][j].o-da[h][j].r)dt=da[h][j].o+da[h][j].c-sy;
            if(dis[da[h][j].n]>dis[h]+da[h][j].r+dt)
            {
                dis[da[h][j].n]=dis[h]+da[h][j].r+dt;
                if(!pk[da[h][j].n])
                {
                    pk[da[h][j].n]=true;
                    que.push(da[h][j].n);
                }
            }
        }
        que.pop();
        pk[h]=false;
    }
}


int main()
{
    int o=0;
    while(~scanf("%d%d%d%d",&n,&m,&s,&t))
    {
        da.clear();
        da.resize(n+1);
        int a,b,c,d,e;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
            if(c<e)continue;
            da[a].push_back(ips(b,c,d,e));
        }
        spfa(s);
        printf("Case %d: %d\n",++o,dis[t]);
    }
    return 0;
}