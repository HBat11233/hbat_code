#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
int f[1005];

int find(int x)
{
    if(x!=f[x])
        f[x]=find(f[x]);
    return f[x];
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int ans=0;
        for(int i=0;i<n;++i)
            f[i]=i;
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int x=find(a);
            int y=find(b);
            if(x==y)
                ans++;
            else
                f[x]=y;
        }
        printf("%d\n",ans);
    }
    return 0;
}