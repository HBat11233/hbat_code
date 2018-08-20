//排列组合
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[32][32];

int main()
{
    for(int i=0;i<32;++i)
        dp[i][0]=dp[i][i]=1;
    for(int i=2;i<32;++i)
        for(int j=1;j<i;++j)
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    for(int i=0;i<32;++i)
        for(int j=1;j<32;++j)
            dp[i][j]+=dp[i][j-1];
    int b,e;
    int pb,lb,pe,le;
    int temp;
    while(~scanf("%d%d",&b,&e))
    {
        pb=lb=pe=le=0;
        temp=b;
        while(temp)
        {
            if(temp&1)pb++;
            temp>>=1;
            lb++;
        }
        temp=e;
        while(temp)
        {
            if(temp&1)pe++;
            temp>>=1;
            le++;
        }
        int ans=0;
        int ne=(lb>>1)-pb;
        temp=b;
        int l=0;
        while(temp!=1)
        {
            if(temp&1)
            {
                ne++;
                if(ne>=0)ans-=dp[l][ne];
            }
            l++;
            temp>>=1;
        }
        temp=e;
        l=0;
        ne=(le>>1)-pe;
        if(ne>=0)ans++;
        while(temp!=1)
        {
            if(temp&1)
            {
                ne++;
                if(ne>=0)ans+=dp[l][ne];
            }
            l++;
            temp>>=1;
        }
        for(int i=lb;i<le;++i)
            ans+=dp[i-1][(i>>1)-1];
        printf("%d\n",ans);
    }
    return 0;
}