#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int pre[2005];
int ans;
struct ips
{
    int a;
    int b;
    int l;
}que[10005];

int find(int N)
{
    return pre[N]==N? N: pre[N]=find(pre[N]);
}

bool cmp(const ips &a,const ips &b)
{
    return a.l<b.l;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        pre[i]=i;
    for(int i=1;i<=m;++i)
        scanf("%d%d%d",&que[i].a,&que[i].b,&que[i].l);
    sort(que+1,que+m+1,cmp);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        x=find(que[i].a);
        y=find(que[i].b);
        if(x!=y)
        {
            if(x>y)
                pre[x]=y;
            else
                pre[y]=x;
            ans=max(ans,que[i].l);
        }
    }
    printf("%d\n",ans);
    return 0;
}