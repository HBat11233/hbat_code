#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int datas[305][305];
int dis[305];
double ans[305];
bool pk[305];
int n,m;

void spfa(int x)
{
    mem(pk,0);
    mem(dis,0x7f);
    queue<int>que;
    dis[x]=0;
    que.push(x);
    pk[x]=true;
    while(!que.empty())
    {
        int h=que.front();
        for(int i=1;i<=n;++i)
            if(dis[i]>dis[h]+datas[h][i])
            {
                dis[i]=dis[h]+datas[h][i];
                if(!pk[i])
                {
                    que.push(i);
                    pk[i]=true;
                }
            }
        que.pop();
        pk[h]=false;
    }
    for(int i=1;i<=n;++i)
        ans[x]+=dis[i];
}

int main()
{
    mem(datas,0x7f);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int temp;
        int tedatas[305];
        scanf("%d",&temp);
        for(int j=0;j<temp;++j)
            scanf("%d",tedatas+j);
        for(int j=0;j<temp;++j)
            for(int k=0;k<temp;++k)
            {
                if(k==j)continue;
                datas[tedatas[j]][tedatas[k]]=1;
                datas[tedatas[k]][tedatas[j]]=1;
            }
    }
    for(int i=1;i<=n;++i)
        spfa(i);
    double mi=0x7fffffff;
    for(int i=1;i<=n;++i)
        mi=min(mi,ans[i]);
    cout<<int(100*(mi/(n-1)))<<'\n';
    return 0;
}