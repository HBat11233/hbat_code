#include <bits/stdc++.h>
#define INF 100005

using namespace std;

int que[INF];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int inf;
        scanf("%d%d",&n,&inf);
        for(int i=0;i<n;++i)
            scanf("%d",que+i);
        sort(que,que+n);
        int b=0;
        for(int i=n-1;i>b;--i)
            if(que[i]+que[b]<=inf)b++;
        printf("%d\n",n-b);
        if(t)printf("\n");
    }
    return 0;
}