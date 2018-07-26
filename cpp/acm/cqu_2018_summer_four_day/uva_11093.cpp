#include <bits/stdc++.h>
#define INF 100005

using namespace std;
int que[INF];
bool pk[INF];

int main()
{
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        int n;
        scanf("%d",&n);
        memset(que,0,sizeof(0));
        for(int i=0;i<n;++i)
            scanf("%d",que+i);
        int temp;
        for(int i=0;i<n;++i)
            scanf("%d",&temp),que[i]-=temp;
        memset(pk,0,sizeof(pk));
        int b=0;
        int car=0;
        int i;
        while(true)
        {
            for(;b<n;++b)
            {
                if(que[b]>=0)break;
                else pk[b]=true;
            }
            if(pk[b]||b==n)
            {
                printf("Case %d: Not possible\n",o);
                break;
            }
            pk[b]=true;
            car=que[b];
            for(i=b+1,i%=n;i!=b;)
            {
                if(car+que[i]<0)break;
                car+=que[i];
                i++;
                i%=n;
            }
            if(i==b)
            {
                printf("Case %d: Possible from station %d\n",o,b+1);
                break;
            }
            b=i+1;
            b%=n;
        }
    }
    return 0;
}