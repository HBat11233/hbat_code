//poj3522(uva1395)(uvalive3887)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff

using namespace std;

struct ips
{
    int a;
    int b;
    int l;
    ips(const int& a=0,const int& b=0,const int& l=0)
    :a(a),b(b),l(l){}
    bool operator <(const ips& b)const
    {
        return l<b.l;
    }
};
int n,m;
vector < ips > da;

int fa[106];

int find(int x)
{
    return fa[x]==x? x:fa[x]=find(fa[x]);
}

int kruskal(int x)
{
    int minn=INF,maxn=-1;
    int num=0;
    for(int i=0;i<106;++i)
        fa[i]=i;
    for(int i=x;i<m;++i)
    {
        int x=find(da[i].a);
        int y=find(da[i].b);
        if(x!=y)
        {
            fa[y]=x;
            minn=min(minn,da[i].l);
            maxn=max(maxn,da[i].l);
            num++;
        }
        if(num==n-1)break;
    }
    if(num==n-1)return maxn-minn;
    else return -1;
}

int main()
{
    while(scanf("%d%d",&n,&m),n+m)
    {
        da.clear();
        da.resize(m);
        for(int i=0;i<m;++i)
            scanf("%d%d%d",&da[i].a,&da[i].b,&da[i].l);
        sort(da.begin(),da.end());
        int ans=INF;
        for(int i=0;i<=m-n+1;++i)
        {
            int temp=kruskal(i);
            if(temp!=-1)ans=min(ans,temp);
        }
        if(ans==INF)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}