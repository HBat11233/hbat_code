//并查集
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int f[10000005];
bool p[10000005];
map<int,int>ans;
int n;

int find(int x)
{
    if(x!=f[x])
        f[x]=find(f[x]);
    return f[x];
}



int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<10000005;++i)
            f[i]=i,p[i]=false;
        int ma=-1,mi=0x7fffffff;
        ans.clear();
        for(int i=0;i<n;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            p[a]=p[b]=true;
            ma=max(ma,max(a,b));
            mi=min(mi,min(a,b));
            int x=find(a);
            int y=find(b);
            if(x!=y)
                f[x]=y;
        }
        int anser=-1;
        for(int i=mi;i<=ma;++i)
        {
            if(!p[i])continue;
            int k=find(i);
            if(!ans.count(k))ans[k]=1;
            else (ans[k]++);
            anser=max(anser,ans[k]);
        }
        if(!n)anser=1;
        cout<<anser<<endl;
    }
    return 0;
}