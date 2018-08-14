#include <bits/stdc++.h>

#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;

int n,s,t,c;
int w[105][105];

int pre[105];
bool pk[105];

bool bfs()
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
            if(!pk[i]&&w[h][i]>0)
            {
                pre[i]=h;
                if(i==t)return true;
                que.push(i);
                pk[i]=true;
            }
        }
        que.pop();
    }
    return false;
}

int EK()
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
            //w[te][pre[te]]+=mins;  //加不加都ac，我觉得应该不加。。
            te=pre[te];
        }
    }
    return ans;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int o=0;
    while(scanf("%d",&n),n)
    {
        mst(w,0);
        scanf("%d%d%d",&s,&t,&c);
        int a,b,k;
        for(int i=0;i<c;++i)
        {
            scanf("%d%d%d",&a,&b,&k);
            w[a][b]+=k;
            w[b][a]+=k;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n",++o,EK());
    }
    return 0;
}