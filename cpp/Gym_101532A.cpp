#include <bits/stdc++.h>
#define INF 100005

using namespace std;

int arr[INF];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int mnum=-1;
        long long ans=0;
        memset(arr,0,sizeof(arr));
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
            mnum=mnum>arr[i]? mnum:arr[i];
        }
        vector <long long> que;
        long long tb=1;
        long long mi=0;
        while(tb<=mnum)
        {
            long long len=0;
            que.clear();
            for(long long i=0;i<n;++i)
            {
                if(tb&arr[i])len++;
                else if(len)
                {
                    que.push_back(len);
                    len=0;
                }
            }
            long long temp=0;
            if(len)temp+=(len*(len+1))/2;
            for(int i=0;i<que.size();++i)
                temp+=(que[i]*(que[i]+1))/2;
            ans+=temp*(1<<mi);
            tb<<=1;
            mi++;
        }
        printf("%d\n",ans);
    }
    return 0;
}