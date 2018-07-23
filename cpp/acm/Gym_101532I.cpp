#include <bits/stdc++.h>
#define INF 200005

using namespace std;

map<int,vector<int> >pos;
int que[INF];
int dp[INF];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        pos.clear();
        memset(dp,127,sizeof(dp));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",que+i);
            pos[que[i]].push_back(i);
        }
        dp[n-1]=0;
        for(int i=n-1;i>0;--i)
        {
            if(pos[que[i]].size()>1)
            {
                dp[pos[que[i]][pos[que[i]].size()-2]]=min(dp[i]+1,dp[pos[que[i]][pos[que[i]].size()-2]]);
                pos[que[i]].pop_back();
            }
            dp[i-1]=min(dp[i-1],dp[i]+1);
        }
        printf("%d\n",dp[0]);
    }
    return 0;
}