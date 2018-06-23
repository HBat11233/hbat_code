//最小生成树
#include <iostream>
#include <cstdio>

using namespace std;

int t;
int maps[505][505];
int n;

int prime()
{
    int ans=0;
    int dt[505];
    int pt[505];
    for(int i=1;i<=n;++i)
        dt[i]=maps[1][i],pt[i]=false;
    pt[1]=true;
    int mi,ip;
    do
    {
        mi=0x7fffffff;
        ip=0;
        for(int i=1;i<=n;++i)
        {
            if(pt[i])continue;
            if(dt[i]<mi)
            {
                mi=dt[i];
                ip=i;
            }
        }
        if(ip==0)break;
        pt[ip]=true;
        if(dt[ip]>ans)ans=dt[ip];
        for(int i=1;i<=n;++i)
        {
            if(pt[i])continue;
            dt[i]=dt[i]<maps[ip][i]?dt[i]:maps[ip][i];
        }
    }while(ip!=0);
    return ans;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",*(maps+i)+j);
        cout<<prime()<<endl;
    }
    return 0;
}