#include <iostream>
#include <cstring>

#define INF 5000005

using namespace std;

int que[INF];
int dp[INF];

int main()
{
    int n;
    int t=0;
    while(~scanf("%d",&n))
    {
        int temp;
        for(int i=0;i<n;++i)
            scanf("%d",&temp),scanf("%d",que+temp);
        int len=1;
        dp[1]=que[1];
        for(int i=2;i<=n;++i)
        {
            int l=1;
            int r=len;
            while(l<=r)
            {
                int mid=((l+r)>>1);
                if(dp[mid]>=que[i])
                    r=mid-1;
                else l=mid+1;
            }
            dp[l]=que[i];
            if(l>len)
                len++;
        }
        printf("Case %d:\nMy king, at most %d road",++t,len);
        if(len!=1) printf("s");
        printf(" can be built.\n\n");
    }
    return 0;
}