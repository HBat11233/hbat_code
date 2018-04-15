#include <iostream>
#include <cstdio>

using namespace std;

int f[1005];
int bt[1005];
int t,n,m;

int find(int x)
{
    if(x!=f[x])
        f[x]=find(f[x]);
    return f[x];
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            f[i]=i,bt[i]=false;
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int x=find(a);
            int y=find(b);
            if(x!=y)f[x]=y;
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int x=find(i);
            if(!bt[x])
            {
                bt[x]=true;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}