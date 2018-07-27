#include <bits/stdc++.h>

#define INF 100005

using namespace std;
int que[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;++i)
            scanf("%d",que+i);
        sort(que,que+n);
        int high=(que[n-1]-que[0])/(m-1);
        int low=0x7fffffff;
        for(int i=1;i<n;++i)
            low=min(low,que[i]-que[i-1]);
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int nm=1;
            int sum=0;
            for(int i=1;i<n&&nm<m;++i)
            {
                sum+=que[i]-que[i-1];
                if(sum>=mid)
                {
                    nm++;
                    sum=0;
                }
            }
            if(nm==m)
                low=mid+1;
            else
                high=mid-1;
        }
        printf("%d\n",high);
    }
    return 0;
}