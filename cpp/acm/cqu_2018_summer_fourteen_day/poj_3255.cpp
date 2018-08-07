#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

#define INF 5005

using namespace std;

struct ips
{
    int next;
    int len;
    ips(const int& next,const int &len)
    :next(next),len(len){}
};
vector <ips> que[INF];
int dis[INF];
int cdis[INF];
bool pk[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=0;i<r;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        que[a].push_back(ips(b,c));
        que[b].push_back(ips(a,c));
    }
    memset(dis,0x7f,sizeof(dis));
    memset(cdis,0x7f,sizeof(cdis));
    queue<int>ques;
    ques.push(1);
    pk[1]=true;
    dis[1]=0;
    while(!ques.empty())
    {
        int h=ques.front();
        for(int i=0;i<que[h].size();++i)
        {
            if(dis[que[h][i].next]>dis[h]+que[h][i].len)
            {
                dis[que[h][i].next]=dis[h]+que[h][i].len;
                if(!pk[que[h][i].next])
                {
                    ques.push(que[h][i].next);
                    pk[que[h][i].next]=true;
                }
            }
        }
        ques.pop();
        pk[h]=false;
    }
    memset(pk,0,sizeof(pk));
    ques.push(n);
    pk[n]=true;
    cdis[n]=0;
    while(!ques.empty())
    {
        int h=ques.front();
        for(int i=0;i<que[h].size();++i)
        {
            if(cdis[que[h][i].next]>cdis[h]+que[h][i].len)
            {
                
                cdis[que[h][i].next]=cdis[h]+que[h][i].len;
                if(!pk[que[h][i].next])
                {
                    ques.push(que[h][i].next);
                    pk[que[h][i].next]=true;
                }
            }
        }
        ques.pop();
        pk[h]=false;
    }
    int ans=0x7fffffff;
    for(int i=1;i<=n;++i)
        for(int j=0;j<que[i].size();++j)
            if(dis[i]+cdis[que[i][j].next]+que[i][j].len>dis[n]&&dis[i]+cdis[que[i][j].next]+que[i][j].len<ans)
                ans=dis[i]+cdis[que[i][j].next]+que[i][j].len;
    cout<<ans<<'\n';
    return 0;
}