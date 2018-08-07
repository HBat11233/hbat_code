//https://blog.csdn.net/zhang20072844/article/details/7788672
//当相邻的两个点没有好感也没有差感，应该设置后一个点指向前一个点，距离为0，表示后一个点至少与前一个点距离为0，而且前一个与后一个距离最远为无穷大，matx初始化为无穷大
//好题
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define INF 1005
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int matx[INF][INF];

int dis[INF];
bool pk[INF];
int n,ml,md;
int num[INF];

int spfa(int x)
{
    mem(dis,0x7f);
    dis[x]=0;
    pk[x]=true;
    queue<int>que;
    que.push(x);
    num[x]++;
    while(!que.empty())
    {
        int h=que.front();
        for(int i=1;i<=n;++i)
        {
            if(dis[i]>dis[h]+matx[h][i])
            {
                dis[i]=dis[h]+matx[h][i];
                if(!pk[i])
                {
                    que.push(i);
                    pk[i]=true;
                    num[i]++;
                    if(num[i]>n)return -1;
                }
            }
        }
        que.pop();
        pk[h]=false;
    }
    return dis[n];
}

int main()
{
    mem(matx,0x7f);
    scanf("%d%d%d",&n,&ml,&md);
    for(int i=2;i<=n;++i)
        matx[i][i-1]=0;
    for(int i=0;i<ml;++i)
    {
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        if(a>b)swap(a,b);
        matx[a][b]=l;
    }
    for(int i=0;i<md;++i)
    {
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        if(a>b)swap(a,b);
        matx[b][a]=-l;
    }
    int ans=spfa(1);
    if(ans>=0x7f7f7f7f)cout<<-2;
    else cout<<ans;
    cout<<'\n';
    return 0;
}