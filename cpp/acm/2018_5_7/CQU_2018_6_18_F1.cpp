#include <bits/stdc++.h>

using namespace std;
#define INF 100005*2
#define MEM(a,b) memset(a,b,sizeof(a))

int x[INF];
int y[INF];
int nexts[INF];
int frista[INF];
int len;
bool pk[INF];

int bfs(int b)
{
    len=0;
    MEM(pk,0);
    int last;
    queue<int>que;
    que.push(b);
    pk[b]=true;
    int k=0;
    while(!que.empty())
    {
        last=que.front();
        if(k==0)k=que.size();
        int h=frista[last];
        while(h!=-1)
        {
            if(!pk[y[h]])
            {
                pk[y[h]]=true;
                que.push(y[h]);
            }
            h=nexts[h];
        }
        k--;
        que.pop();
        if(k==0)len++;
    }
    return last;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        MEM(frista,-1);
        MEM(nexts,-1);
        for(int i=1;i<2*n-1;++i)
        {
            scanf("%d%d",x+i,y+i);
            nexts[i]=frista[x[i]];
            frista[x[i]]=i;
            x[i+1]=y[i];
            y[i+1]=x[i];
            ++i;
            nexts[i]=frista[x[i]];
            frista[x[i]]=i;
        }
        bfs(bfs(1));
        printf("%d\n",len-1);
    }
    return 0;
}