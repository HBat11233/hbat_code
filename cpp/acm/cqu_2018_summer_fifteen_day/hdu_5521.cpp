#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define INF 100005

using namespace std;

struct ips
{
    int n;
    long long l;
    ips(const int &n,const long long &l)
    :n(n),l(l){}
};

int n,m;
vector< vector<ips> >da;
long long dis[INF*2][2];
bool pk[INF*2];
int ans[INF];
int pos;

void spfa(int x,int pos)
{
    queue<int>que;
    memset(pk,0,sizeof(pk));
    pk[x]=true;
    que.push(x);
    dis[x][pos]=0;
    while(!que.empty())
    {
        int h=que.front();
        for(int i=0;i<da[h].size();++i)
            if(dis[da[h][i].n][pos]>dis[h][pos]+da[h][i].l)
            {
                dis[da[h][i].n][pos]=dis[h][pos]+da[h][i].l;
                if(!pk[da[h][i].n])
                {
                    pk[da[h][i].n]=true;
                    que.push(da[h][i].n);
                }
            }
        que.pop();
        pk[h]=false;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        da.clear();
        scanf("%d%d",&n,&m);
        da.resize(n+m+2);
        for(int i=1;i<=m;++i)
        {
            int ti,s;
            scanf("%d%d",&ti,&s);
            int te;
            for(int j=0;j<s;++j)
            {
                scanf("%d",&te);
                da[te].push_back(ips(n+i,ti));
                da[n+i].push_back(ips(te,ti));
            }
        }
        memset(dis,0x7f,sizeof(dis));
        spfa(1,0);
        spfa(n,1);
        long long tm=0x7fffffffffffffff;
        for(int i=1;i<n;++i)
            tm=min(tm,max(dis[i][0],dis[i][1]));
        pos=0;
        for(int i=1;i<=n;++i)
            if(tm==max(dis[i][0],dis[i][1]))ans[pos++]=i;
        if(tm>=0x7fffffff)printf("Case #%d: Evil John\n",o);
        else
        {
            printf("Case #%d: %lld\n",o,tm/2);
            for(int i=0;i<pos;++i)
                if(i==pos-1)printf("%lld\n",ans[i]);
                else printf("%lld ",ans[i]);
        }
    }
    return 0;
}