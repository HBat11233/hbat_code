#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define mem(a,b) memset(a,b,sizeof(a))
#define INF 10005
#define NV 10000

using namespace std;

int pre[INF*2];
struct ips
{
    int a;
    int b;
    int l;
    bool operator <(const ips& b)const
    {
        return l>b.l;
    }
}que[INF*5];


int find(int n)
{
    return pre[n]==n? n:pre[n]=find(pre[n]);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(que,0);
        for(int i=0;i<INF*2;++i)
            pre[i]=i;
        int n,m,r;
        scanf("%d%d%d",&n,&m,&r);
        for(int i=0;i<r;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            que[i].a=a,que[i].b=b+NV,que[i].l=c;
        }
        sort(que,que+r);
        int sum=0;
        for(int i=0;i<r;++i)
        {
            int x=find(que[i].a);
            int y=find(que[i].b);
            if(x!=y)
            {
                pre[y]=x;
                sum+=que[i].l;
            }
        }
        int ans=10000*(n+m)-sum;
        cout<<ans<<'\n';
    }
    return 0;
}