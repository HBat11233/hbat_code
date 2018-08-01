#include <iostream>
#include <cstdio>
#include <algorithm>

#define INF 100005

using namespace std;

long long a[INF];
long long b[INF];

bool _comp(const int &a,const int &b)
{
    return a>b;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int temp;
        for(int i=0;i<n;++i)
        {
            scanf("%lld%d",a+i,&temp);
            b[i]=a[i]-temp;
        }
        long long sum=0;
        for(int i=0;i<n;++i)
            sum+=a[i];
        sort(b,b+n,_comp);
        int ans=0;
        int i;
        for(i=0;i<n;++i)
        {
            if(sum<=m)break;
            sum-=b[i];
            ans++;
        }
        if(i==n&&sum>m)printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}