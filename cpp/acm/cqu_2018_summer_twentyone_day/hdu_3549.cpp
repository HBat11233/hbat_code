//一般的EK
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

#define mst(a,b) memset(a,b,sizeof(a))

using namespace std;

int n,m;
int w[20][20];

int pre[20];
bool pk[20];

bool bfs(int s=1,int t=n)
{
    mst(pre,0);
    mst(pk,0);
    queue<int>que;
    que.push(s);
    pre[s]=s;
    pk[s]=true;
    while(!que.empty())
    {
        int h=que.front();
        for(int i=1;i<=n;++i)
        {
            if(w[h][i]>0&&!pk[i])
            {
                pre[i]=h;
                if(i==t)return true;
                pk[i]=true;
                que.push(i);
            }
        }
        que.pop();
       // pk[h]=false;//是bfs不是spfa。。。。
    }
    return false;
}

int EK(int s=1,int t=n)
{
    int ans=0;
    while(bfs())
    {
        int te=t;
        int mins=0x7fffffff;
        while(te!=pre[te])
        {
            mins=min(mins,w[pre[te]][te]);
            te=pre[te];
        }
        ans+=mins;
        te=t;
        while(te!=pre[te])
        {
            w[pre[te]][te]-=mins;
            w[te][pre[te]]+=mins;
            te=pre[te];
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        mst(w,0);
        scanf("%d%d",&n,&m);
        int a,b,c;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&a,&b,&c);
            w[a][b]+=c;
        }
        printf("Case %d: %d\n",o,EK());
    }
    return 0;
}