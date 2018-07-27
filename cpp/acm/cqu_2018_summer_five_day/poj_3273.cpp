#include <iostream>
#include <cstdio>
#include <cstdlib>

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
        int low=-1,high=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",que+i);
            low=max(low,que[i]);
            high+=que[i];
        }
        int ans=(low+high)>>1;
        int nm=0;
        while(low<high)
        {
            int temp=0;
            nm=0;
            for(int i=0;i<n;++i)
            {
                temp+=que[i];
                if(temp>ans)
                {
                    nm++;
                    temp=que[i];
                }
            }
            nm++;
            if(nm>m)
                low=ans+1;
            else if(nm<=m)
                high=ans-1;
            ans=(low+high)>>1;
        }
        printf("%d\n",low);
    }
    return 0;
}