//aizu 2249
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

struct da
{
    int la;
    int d;
    int c;
    da(int la=0,int d=0,int c=0):
        la(la),d(d),c(c){}
};
map<int,vector < da > >lm;
bool pk[10001];
int n,m;
int dis[10001];
int last[10001];
int lastl[10001];

int main()
{
    while(scanf("%d%d",&n,&m),n+m)
    {
        lm.clear();
        memset(pk,0,sizeof(pk));
        memset(dis,0x7f,sizeof(dis));
        memset(last,-1,sizeof(last));
        memset(lastl,-1,sizeof(lastl));
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            da tm;
            cin>>tm.d>>tm.c;
            tm.la=b;
            lm[a].push_back(tm);
            tm.la=a;
            lm[b].push_back(tm);
        }
        dis[1]=0;
        queue<int>que;
        que.push(1);
        pk[1]=true;
        while(!que.empty())
        {
            int h=que.front();
            for(int i=0;i<lm[h].size();++i)
            {
                int k=lm[h][i].la;
                if(dis[k]>dis[h]+lm[h][i].d)
                {
                    dis[k]=dis[h]+lm[h][i].d;
                    last[k]=h;
                    lastl[k]=lm[h][i].c;
                    if(!pk[k])
                    {
                        pk[k]=true;
                        que.push(k);
                    }
                }else if(last[k]!=-1&&dis[k]==dis[h]+lm[h][i].d&&h!=k)
                {
                    if(lastl[k]>lm[h][i].c)
                    {
                        last[k]=h;
                        lastl[k]=lm[h][i].c;
                        if(!pk[k])
                        {
                            pk[k]=true;
                            que.push(k);
                        }
                    }
                }
            }
            que.pop();
            pk[h]=false;
        }
        int ans=0;
        for(int i=n;i>1;--i)
            ans+=lastl[i];
        printf("%d\n",ans);
    }
    return 0;
}