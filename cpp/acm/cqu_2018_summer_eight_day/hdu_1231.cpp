#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 10005

using namespace std;

int arr[INF];
int sum[INF];
int dp[INF];
int dpmin[INF];
int dppos[INF];

int main()
{
    int k;
    while(scanf("%d",&k),k)
    {
        int l,r;
        for(int i=0;i<k;++i)
            scanf("%d",&arr[i]);
        dpmin[0]=sum[0]=arr[0];
        dppos[0]=0;
        for(int i=1;i<k;++i)
            sum[i]=sum[i-1]+arr[i];
        for(int i=1;i<k;++i)
            if(dpmin[i-1]<sum[i])dpmin[i]=dpmin[i-1],dppos[i]=dppos[i-1];
            else dpmin[i]=sum[i],dppos[i]=i;
        l=r=dp[0]=sum[0];
        for(int i=1;i<k;++i)
        {
            int tm=sum[i];
            int tl=arr[0],tr=arr[i];
            if(dpmin[i-1]<0)
            {
                tm=sum[i]-dpmin[i-1];
                tl=arr[dppos[i-1]+1];
            }
            if(tm>dp[i-1])
            {
                dp[i]=tm;
                l=tl;
                r=tr;
            }else dp[i]=dp[i-1];
        }
        if(dp[k-1]>=0)//瞎，不看题。
            printf("%d %d %d\n",dp[k-1],l,r);
        else
            printf("%d %d %d\n",0,arr[0],arr[k-1]);
    }
    return 0;
}