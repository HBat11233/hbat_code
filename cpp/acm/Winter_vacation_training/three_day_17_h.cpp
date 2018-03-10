#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f

using namespace std;

int frist[50010];
int nexts[50010];
int wx[50010],wy[50010];
int dis[1001];

int pve[1001];
bool ks[1001];

void print(int &k)
{
    if(pve[k]!=0)print(pve[k]);
    cout<<k<<endl;
}

int main()
{
    memset(frist,-1,sizeof(frist));
    memset(nexts,-1,sizeof(nexts));
    for(int i=0;i<1001;++i)
    {
        dis[i]=INF;
    }
    dis[1]=0;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",wx+i,wy+i);
        nexts[i]=frist[wx[i]];
        frist[wx[i]]=i;
    }
    queue<int>que;
    que.push(1);
    ks[1]=true;
    while(!que.empty())
    {
        int head=que.front();
        int t=frist[head];
        while(t!=-1)
        {
            if(dis[wy[t]]>dis[wx[t]]+1)
            {
                dis[wy[t]]=dis[wx[t]]+1;
                if(!ks[wy[t]])
                {
                    que.push(wy[t]);
                    ks[wy[t]]=true;
                    pve[wy[t]]=wx[t];
                }
            }
            t=nexts[t];
        }
        que.pop();
        ks[head]=false;
    }
    if(dis[k]>=INF)cout<<-1<<endl;
    else
    {
        cout<<dis[k]+1<<endl;
        print(k);
    }
    system("pause");
    return 0;
}