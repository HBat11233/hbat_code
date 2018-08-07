#include <bits/stdc++.h>

#define mem(a,b) memset(a,b,sizeof(a))
#define INF 100005

using namespace std;

int dp[1<<16];
int he[20];
int atk[20][20];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        mem(dp,0x7f);
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",he+i);
        for(int i=0;i<n;++i)
        {
            getchar();
            char ch;
            for(int j=0;j<n;++j)
            {
                ch=getchar();
                atk[i][j]=ch-'0';
            }
        }
        for(int i=0;i<n;++i)
            dp[1<<i]=he[i];
        int len=1<<n;
        for(int i=3;i<len;++i)
        {
            for(int j=0;j<n;++j)
            {
                int temp=1<<j;
                if(temp&i)
                {
                    dp[i]=min(dp[i^temp]+he[j],dp[i]);
                    int maxn=-1;
                    for(int k=0;k<n;++k)
                        if(i&(1<<k)&&k!=j) maxn=max(maxn,atk[k][j]);
                    if(maxn)dp[i]=min(dp[i],dp[i^temp]+(int)((double)he[j]/maxn+0.99999));
                }
            }
        }
        printf("Case %d: %d\n",o,dp[(1<<n)-1]);
    }
    return 0;
}