#include <iostream>
#include <cstdio>

#define INF 1000005

using namespace std;

int que[2000];
int sum[2000];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    que[0]=0;
    que[1]=2;
    que[2]=3;
    que[3]=5;
    sum[0]=0;
    for(int i=4,j=7;i<2000;++j)
    {
        int o;
        for(o=1;que[o]*que[o]<=j;++o)
            if(j%que[o]==0)break;
        if(que[o]*que[o]>j)
        {
            que[i]=j;
            i++;
        }
    }
    for(int i=1;i<2000;++i)
        sum[i]=que[i]+sum[i-1];
    int n;
    while(scanf("%d",&n),n)
    {
        int ans=0;
        for(int i=1,j=0;i<=n;++j)
        {
            while(sum[i]-sum[j]<n&&i<=n)
                i++;
            if(sum[i]-sum[j]==n)ans++;
            else if(sum[i]+sum[j]<n)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}