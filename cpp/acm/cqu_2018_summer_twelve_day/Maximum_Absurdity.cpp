#include <bits/stdc++.h>

#define INF 200005

using namespace std;

typedef long long LL;

LL que[INF];
LL dp1[INF];
LL dp2[INF];
int pos[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%lld",que+i);
    for(int i=1;i<=n;++i)
        que[i]+=que[i-1];
    int posa,posb;
    dp1[k]=que[k];
    pos[k]=1;
    for(int i=k+1;i<=n;++i)
        if(dp1[i-1]<que[i]-que[i-k])
        {
            dp1[i]=que[i]-que[i-k];
            pos[i]=i-k+1;
        }else
        {
            dp1[i]=dp1[i-1];
            pos[i]=pos[i-1];
        }
    dp2[2*k]=que[2*k];
    posa=1;
    posb=k+1;
    for(int i=2*k+1;i<=n;++i)
        if(dp2[i-1]<dp1[i-k]+(que[i]-que[i-k]))
        {
            dp2[i]=dp1[i-k]+(que[i]-que[i-k]);
            posa=pos[i-k];
            posb=i-k+1;
        }else dp2[i]=dp2[i-1];;
    printf("%d %d\n",posa,posb);
    return 0;
}