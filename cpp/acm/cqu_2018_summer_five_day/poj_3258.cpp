#include <iostream>
#include <cstdio>
#include <algorithm>

#define INF 500005

using namespace std;

int que[INF];
int quj[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int l,n,m;
    while(~scanf("%d%d%d",&l,&n,&m))
    {
        for(int i=0;i<n;++i)
            scanf("%d",que+i);
        sort(que,que+n);
        quj[0]=que[0];
        quj[n]=l-que[n-1];
        for(int i=1;i<n;++i)
            quj[i]=que[i]-que[i-1];
        int high=l,low=0x7fffffff;
        for(int i=0;i<=n;++i)
            low=min(quj[i],low);
        while(low<high)
        {
            int temp;
            int nm=0;
            int mid=(low+high)>>1;
            int ps=0;
            for(ps=0;ps<=n;++ps)
                if(quj[ps]<mid)
                {
                    temp=quj[ps];
                    break;
                }
            for(int i=1+ps;i<=n;++i)
            {
                temp+=quj[i];
                nm++;
                if(temp>=mid)
                {
                    temp=0;
                    if(i!=n)nm--;
                }else if(i==n)nm++;
            }
            if(nm>m)high=mid-1;
            else if(nm==m)high=mid;
            else low=mid+1;/*
            if(low>=high&&nm==m)
            {
                low=mid;
                break;
            }*/
        }
        printf("%d\n",high);
    }
    return 0;
}

16 6 5
1 3 6 10 13 15